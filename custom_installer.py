import os, sys, git, json, urllib2, shutil



path = "{0}".format(os.path.dirname(os.path.realpath(__file__)))

git_repo = sys.argv[1]

folder_name = git_repo.split('/')[-1].split('.')[0]

component_name = None



os.makedirs("{0}/tmp".format(path))

git.Git("{0}/tmp".format(path)).clone(git_repo)



for file in os.listdir("{0}/tmp/{1}".format(path, folder_name)):

   if file.endswith(".json"):

       with open(os.path.join("{0}/tmp/{1}".format(path, folder_name), file), 'r') as f:

           datastore = json.load(f)

           component_names = datastore.keys()

           for component_name in component_names:

               component_name = str(component_name.encode("utf-8"))

               datastore_current = datastore.get(component_name)

               print("Setting up custom component {0} version {1}".format(str(component_name), datastore_current['version']))

               local_dir = "{0}{1}".format(path, os.path.dirname(datastore_current['local_location']))

               print("Installing to {0}".format(local_dir))

               try:

                   os.makedirs(local_dir)

               except:

                   pass

               try:

                   datastore_current['resources'].append(datastore_current['remote_location'])

               except:

                   datastore_current['resources'] = [datastore_current['remote_location']]

               for x in datastore_current['resources']:

                   print("Downloading: {0}".format(x))

                   response = urllib2.urlopen(x)

                   local_file = open("{0}/{1}".format(local_dir, x.split('/')[-1]), "wb")

                   print("  To: {0}".format("{0}/{1}".format(local_dir, x.split('/')[-1])))

                   local_file.write(response.read())

                   local_file.close()



shutil.rmtree("{0}/tmp".format(path), ignore_errors=True)