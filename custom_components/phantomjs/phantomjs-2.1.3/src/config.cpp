/*
  This file is part of the PhantomJS project from Ofi Labs.

  Copyright (C) 2012 Ariya Hidayat <ariya.hidayat@gmail.com>
  Copyright (C) 2011 Ariya Hidayat <ariya.hidayat@gmail.com>
  Copyright (C) 2011 execjosh, http://execjosh.blogspot.com
  Copyright (C) 2013 James M. Greene <james.m.greene@gmail.com>

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
  THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "config.h"
#include <QDir>
#include <QFileInfo>
#include <QWebPage>
#include <QWebFrame>
#include <QNetworkProxy>
#include "terminal.h"
#include "utils.h"
#include "consts.h"
#include <iostream>


<<<<<<< HEAD
static const struct QCommandLineConfigEntry flags[] =
{
    { QCommandLine::Option, '\0', "cookies-file", "Sets the file name to store the persistent cookies", QCommandLine::Optional },
    { QCommandLine::Option, '\0', "config", "Specifies JSON-formatted configuration file", QCommandLine::Optional },
    { QCommandLine::Option, '\0', "debug", "Prints additional warning and debug message: 'true' or 'false' (default)", QCommandLine::Optional },
    { QCommandLine::Option, '\0', "disk-cache", "Enables disk cache: 'true' or 'false' (default)", QCommandLine::Optional },
    { QCommandLine::Option, '\0', "ignore-ssl-errors", "Ignores SSL errors (expired/self-signed certificate errors): 'true' or 'false' (default)", QCommandLine::Optional },
    { QCommandLine::Option, '\0', "load-images", "Loads all inlined images: 'true' (default) or 'false'", QCommandLine::Optional },
    { QCommandLine::Option, '\0', "local-storage-path", "Specifies the location for offline local storage", QCommandLine::Optional },
    { QCommandLine::Option, '\0', "local-storage-quota", "Sets the maximum size of the offline local storage (in KB)", QCommandLine::Optional },
    { QCommandLine::Option, '\0', "local-to-remote-url-access", "Allows local content to access remote URL: 'true' or 'false' (default)", QCommandLine::Optional },
    { QCommandLine::Option, '\0', "max-disk-cache-size", "Limits the size of the disk cache (in KB)", QCommandLine::Optional },
    { QCommandLine::Option, '\0', "output-encoding", "Sets the encoding for the terminal output, default is 'utf8'", QCommandLine::Optional },
    { QCommandLine::Option, '\0', "remote-debugger-port", "Starts the script in a debug harness and listens on the specified port", QCommandLine::Optional },
    { QCommandLine::Option, '\0', "remote-debugger-autorun", "Runs the script in the debugger immediately: 'true' or 'false' (default)", QCommandLine::Optional },
    { QCommandLine::Option, '\0', "proxy", "Sets the proxy server, e.g. '--proxy=http://proxy.company.com:8080'", QCommandLine::Optional },
    { QCommandLine::Option, '\0', "proxy-auth", "Provides authentication information for the proxy, e.g. ''-proxy-auth=username:password'", QCommandLine::Optional },
    { QCommandLine::Option, '\0', "proxy-type", "Specifies the proxy type, 'http' (default), 'none' (disable completely), or 'socks5'", QCommandLine::Optional },
    { QCommandLine::Option, '\0', "script-encoding", "Sets the encoding used for the starting script, default is 'utf8'", QCommandLine::Optional },
    { QCommandLine::Option, '\0', "script-language", "Sets the script language instead of detecting it: 'javascript', 'coffeescript'", QCommandLine::Optional },
    { QCommandLine::Option, '\0', "web-security", "Enables web security, 'true' (default) or 'false'", QCommandLine::Optional },
    { QCommandLine::Option, '\0', "ssl-protocol", "Sets the SSL protocol (supported protocols: 'SSLv3' (default), 'SSLv2', 'TLSv1', 'any')", QCommandLine::Optional },
    { QCommandLine::Option, '\0', "ssl-certificates-path", "Sets the location for custom CA certificates (if none set, uses system default)", QCommandLine::Optional },
    { QCommandLine::Option, '\0', "webdriver", "Starts in 'Remote WebDriver mode' (embedded GhostDriver): '[[<IP>:]<PORT>]' (default '127.0.0.1:8910') ", QCommandLine::Optional },
    { QCommandLine::Option, '\0', "webdriver-logfile", "File where to write the WebDriver's Log (default 'none') (NOTE: needs '--webdriver') ", QCommandLine::Optional },
    { QCommandLine::Option, '\0', "webdriver-loglevel", "WebDriver Logging Level: (supported: 'ERROR', 'WARN', 'INFO', 'DEBUG') (default 'INFO') (NOTE: needs '--webdriver') ", QCommandLine::Optional },
    { QCommandLine::Option, '\0', "webdriver-selenium-grid-hub", "URL to the Selenium Grid HUB: 'URL_TO_HUB' (default 'none') (NOTE: needs '--webdriver') ", QCommandLine::Optional },
    { QCommandLine::Option, '\0', "webdriver-selenium-grid-remote-proxy-class", "Sets the remote proxy class used by the hub for the node, e.g. '--webdriver-selenium-grid-remote-proxy-class=org.openqa.grid.selenium.proxy.DefaultRemoteProxy'", QCommandLine::Optional },
    { QCommandLine::Param, '\0', "script", "Script", QCommandLine::Flags(QCommandLine::Optional|QCommandLine::ParameterFence)},
    { QCommandLine::Param, '\0', "argument", "Script argument", QCommandLine::OptionalMultiple },
    { QCommandLine::Switch, 'w', "wd", "Equivalent to '--webdriver' option above", QCommandLine::Optional },
    { QCommandLine::Switch, 'h', "help", "Shows this message and quits", QCommandLine::Optional },
    { QCommandLine::Switch, 'v', "version", "Prints out PhantomJS version", QCommandLine::Optional },
    QCOMMANDLINE_CONFIG_ENTRY_END
=======
static const QCommandLineOption cookiesFileOption("cookies-file", "Sets the file name to store the persistent cookies", "cookies-file");
static const QCommandLineOption configOption("config", "Specifies JSON-formatted configuration file", "config");
static const QCommandLineOption debugOption("debug", "Prints additional warning and debug message: 'true' or 'false' (default)", "debug");
static const QCommandLineOption diskCacheOption("disk-cache", "Enables disk cache: 'true' or 'false' (default)", "disk-cache");
static const QCommandLineOption ignoreSslErrorsOption("ignore-ssl-errors", "Ignores SSL errors (expired/self-signed certificate errors): 'true' or 'false' (default)", "ignore-ssl-errors");
static const QCommandLineOption loadImagesOption("load-images", "Loads all inlined images: 'true' (default) or 'false'", "load-images");
static const QCommandLineOption localStoragePathOption("local-storage-path", "Specifies the location for offline local storage", "local-storage-path");
static const QCommandLineOption localStorageQuotaOption("local-storage-quota", "Sets the maximum size of the offline local storage (in KB)", "local-storage-quota");
static const QCommandLineOption localUrlAccessOption("local-url-access", "Allows use of 'file:///' URLs: 'true' (default) or 'false'", "local-url-access");
static const QCommandLineOption localToRemoteUrlAccessOption("local-to-remote-url-access", "Allows local content to access remote URL: 'true' or 'false' (default)", "local-to-remote-url-access");
static const QCommandLineOption maxDiskCacheSizeOption("max-disk-cache-size", "Limits the size of the disk cache (in KB)", "maxDiskCacheSizeOption");
static const QCommandLineOption outputEncodingOption("output-encoding", "Sets the encoding for the terminal output, default is 'utf8'", "output-encoding");
static const QCommandLineOption remoteDebuggerPortOption("remote-debugger-port", "Starts the script in a debug harness and listens on the specified port", "remote-debugger-port");
static const QCommandLineOption remoteDebuggerAutorunOption("remote-debugger-autorun", "Runs the script in the debugger immediately: 'true' or 'false' (default)", "remote-debugger-autorun");
static const QCommandLineOption proxyOption("proxy", "Sets the proxy server, e.g. '--proxy=http://proxy.company.com:8080'", "proxy");
static const QCommandLineOption proxyAuthOption("proxy-auth", "Provides authentication information for the proxy, e.g. ''-proxy-auth=username:password'", "proxy-auth");
static const QCommandLineOption proxyTypeOption("proxy-type", "Specifies the proxy type, 'http' (default), 'none' (disable completely), or 'socks5'", "proxy-type");
static const QCommandLineOption scriptEncodingOption("script-encoding", "Sets the encoding used for the starting script, default is 'utf8'", "script-encoding");
static const QCommandLineOption scriptLanguageOption("script-language", "Sets the script language instead of detecting it: 'javascript'", "script-language");
static const QCommandLineOption webSecurityOption("web-security", "Enables web security, 'true' (default) or 'false'", "web-security");
static const QCommandLineOption sslProtocolOption("ssl-protocol", "Selects a specific SSL protocol version to offer. Values (case insensitive): TLSv1.2, TLSv1.1, TLSv1.0, TLSv1 (same as v1.0), SSLv3, or ANY. Default is to offer all that Qt thinks are secure (SSLv3 and up). Not all values may be supported, depending on the system OpenSSL library.", "ssl-protocol");
static const QCommandLineOption sslCiphersOption("ssl-ciphers", "Sets supported TLS/SSL ciphers. Argument is a colon-separated list of OpenSSL cipher names (macros like ALL, kRSA, etc. may not be used). Default matches modern browsers.", "ssl-ciphers");
static const QCommandLineOption sslCertificatesPathOption("ssl-certificates-path", "Sets the location for custom CA certificates (if none set, uses system default)", "ssl-certificates-path");
static const QCommandLineOption webdriverLogfileOption("webdriver-logfile", "File where to write the WebDriver's Log (default 'none') (NOTE: needs '--webdriver') ", "webdriver-logfile");
static const QCommandLineOption webdriverLogLevelOption("webdriver-loglevel", "WebDriver Logging Level: (supported: 'ERROR', 'WARN', 'INFO', 'DEBUG') (default 'INFO') (NOTE: needs '--webdriver') ", "webdriver-loglever");
static const QCommandLineOption webdriverSeleniumGridHubOption("webdriver-selenium-grid-hub", "URL to the Selenium Grid HUB: 'URL_TO_HUB' (default 'none') (NOTE: needs '--webdriver') ", "webdriver-selenium-grid-hub");
static const QCommandLineOption webdriverAddressOption("webdriver-address", "Set the 'Remote WebDriver mode' address '[[<IP>:]<PORT>]' (default '127.0.0.1:8910') ", "webdriver-address", "127.0.0.1:8910");

static const QCommandLineOption scriptOption("script", "Script", "script");
static const QCommandLineOption scriptArgumentOption("scriptArgument", "Script argument", "scriptArgument");

static const QCommandLineOption helpOption({ "h", "help" }, "Shows this message and quits");
static const QCommandLineOption versionOption({ "v", "version" }, "Prints out PhantomJS version");
static const QCommandLineOption webdriverOption({ "w", "wd", "webdriver" }, "Will start PhantomJS in 'Remote WebDriver mode'");


struct UnknownOptionException {
	const QString &m_optionName;
	explicit UnknownOptionException(const QString &optionName)
		:m_optionName(optionName){}
>>>>>>> 20da5b0a41b28bcc3b94ab761150338a59f5b84e
};



Config::Config(QObject *parent)
    : QObject(parent)
{
<<<<<<< HEAD
    m_cmdLine = new QCommandLine;

    // We will handle --help and --version ourselves in phantom.cpp
    m_cmdLine->enableHelp(false);
    m_cmdLine->enableVersion(false);

=======
>>>>>>> 20da5b0a41b28bcc3b94ab761150338a59f5b84e
    resetToDefaults();
}

void Config::init(const QStringList *const args)
{
    resetToDefaults();

    QByteArray envSslCertDir = qgetenv("SSL_CERT_DIR");
    if (!envSslCertDir.isEmpty())
        setSslCertificatesPath(envSslCertDir);

    processArgs(*args);
}

void Config::processArgs(const QStringList &args)
{
	m_parser.addOption(helpOption);
	m_parser.addOption(versionOption);
	m_parser.addOption(cookiesFileOption);
	m_parser.addOption(configOption);
	m_parser.addOption(debugOption);
	m_parser.addOption(diskCacheOption);
	m_parser.addOption(ignoreSslErrorsOption);
	m_parser.addOption(loadImagesOption);
	m_parser.addOption(localStoragePathOption);
	m_parser.addOption(localStorageQuotaOption);
	m_parser.addOption(localUrlAccessOption);
	m_parser.addOption(localToRemoteUrlAccessOption);
	m_parser.addOption(maxDiskCacheSizeOption);
	m_parser.addOption(outputEncodingOption);
	m_parser.addOption(remoteDebuggerPortOption);
	m_parser.addOption(remoteDebuggerAutorunOption);
	m_parser.addOption(proxyOption);
	m_parser.addOption(proxyAuthOption);
	m_parser.addOption(proxyTypeOption);
	m_parser.addOption(scriptEncodingOption);
	m_parser.addOption(scriptLanguageOption);
	m_parser.addOption(webSecurityOption);
	m_parser.addOption(sslProtocolOption);
	m_parser.addOption(sslCiphersOption);
	m_parser.addOption(sslCertificatesPathOption);
	m_parser.addOption(webdriverOption);
	m_parser.addOption(webdriverAddressOption);
	m_parser.addOption(webdriverLogfileOption);
	m_parser.addOption(webdriverLogLevelOption);
	m_parser.addOption(webdriverSeleniumGridHubOption);


	if (!m_parser.parse(args)) {
		handleError(m_parser.errorText());
		return;
	}

	try	{
		handleSwitches();
		handleOptions();
		handleParams();
	}
	catch (const UnknownOptionException& unknownOptionException) {
		setUnknownOption(QString("Invalid values for '%1' option.").arg(unknownOptionException.m_optionName));
		return;
	}

    // Inject command line parameters to be picked up by GhostDriver
    if (isWebdriverMode()) {
        QStringList argsForGhostDriver;

        m_scriptFile = "main.js";                                           //< launch script

        argsForGhostDriver << QString("--ip=%1").arg(m_webdriverIp);        //< "--ip=IP"
        argsForGhostDriver << QString("--port=%1").arg(m_webdriverPort);    //< "--port=PORT"
        argsForGhostDriver << QString("--proxy=%1").arg(m_webdriverSeleniumGridRemoteProxyClass);    //< "--proxy=FQCN"
        argsForGhostDriver << QString("--version=%1").arg(PHANTOMJS_VERSION_STRING);

        if (!m_webdriverSeleniumGridHub.isEmpty()) {
            argsForGhostDriver << QString("--hub=%1").arg(m_webdriverSeleniumGridHub);  //< "--hub=SELENIUM_GRID_HUB_URL"
        }

        if (!m_webdriverLogFile.isEmpty()) {
            argsForGhostDriver << QString("--logFile=%1").arg(m_webdriverLogFile);          //< "--logFile=LOG_FILE"
            argsForGhostDriver << "--logColor=false";                                   //< Force no-color-output in Log File
        }

        argsForGhostDriver << QString("--logLevel=%1").arg(m_webdriverLogLevel);    //< "--logLevel=LOG_LEVEL"

        // Clear current args and override with those
        setScriptArgs(argsForGhostDriver);
    }
}

void Config::loadJsonFile(const QString &filePath)
{
    QString jsonConfig;
    QFile f(filePath);

    // Check file exists and is readable
    if (!f.exists() || !f.open(QFile::ReadOnly | QFile::Text)) {
        Terminal::instance()->cerr("Unable to open config: \"" + filePath + "\"");
        return;
    }

    // Read content
    jsonConfig = QString::fromUtf8(f.readAll().trimmed());
    f.close();

    // Check it's a valid JSON format
    if (jsonConfig.isEmpty() || !jsonConfig.startsWith('{') || !jsonConfig.endsWith('}')) {
        Terminal::instance()->cerr("Config file MUST be in JSON format!");
        return;
    }

    // Load configurator
    QString configurator = Utils::readResourceFileUtf8(":/configurator.js");

    // Use a temporary QWebPage to load the JSON configuration in this Object using the 'configurator' above
    QWebPage webPage;
    // Add this object to the global scope
    webPage.mainFrame()->addToJavaScriptWindowObject("config", this);
    // Apply the JSON config settings to this very object
    webPage.mainFrame()->evaluateJavaScript(configurator.arg(jsonConfig), QString());
}

QString Config::helpText() const
{
	return m_parser.helpText();
}

bool Config::autoLoadImages() const
{
    return m_autoLoadImages;
}

void Config::setAutoLoadImages(const bool value)
{
    m_autoLoadImages = value;
}

QString Config::cookiesFile() const
{
    return m_cookiesFile;
}

void Config::setCookiesFile(const QString &value)
{
    m_cookiesFile = value;
}

QString Config::offlineStoragePath() const
{
    return m_offlineStoragePath;
}

void Config::setOfflineStoragePath(const QString &value)
{
    QDir dir(value);
    m_offlineStoragePath = dir.absolutePath();
}

int Config::offlineStorageDefaultQuota() const
{
    return m_offlineStorageDefaultQuota;
}

void Config::setOfflineStorageDefaultQuota(int offlineStorageDefaultQuota)
{
    m_offlineStorageDefaultQuota = offlineStorageDefaultQuota * 1024;
}

bool Config::diskCacheEnabled() const
{
    return m_diskCacheEnabled;
}

void Config::setDiskCacheEnabled(const bool value)
{
    m_diskCacheEnabled = value;
}

int Config::maxDiskCacheSize() const
{
    return m_maxDiskCacheSize;
}

void Config::setMaxDiskCacheSize(int maxDiskCacheSize)
{
    m_maxDiskCacheSize = maxDiskCacheSize;
}

bool Config::ignoreSslErrors() const
{
    return m_ignoreSslErrors;
}

void Config::setIgnoreSslErrors(const bool value)
{
    m_ignoreSslErrors = value;
}

bool Config::localToRemoteUrlAccessEnabled() const
{
    return m_localToRemoteUrlAccessEnabled;
}

void Config::setLocalToRemoteUrlAccessEnabled(const bool value)
{
    m_localToRemoteUrlAccessEnabled = value;
}

QString Config::outputEncoding() const
{
    return m_outputEncoding;
}

void Config::setOutputEncoding(const QString &value)
{
    if (value.isEmpty()) {
        return;
    }

    m_outputEncoding = value;
}

QString Config::proxyType() const
{
    return m_proxyType;
}

void Config::setProxyType(const QString value)
{
    m_proxyType = value;
}

QString Config::proxy() const
{
    return m_proxyHost + ":" + QString::number(m_proxyPort);
}

void Config::setProxy(const QString &value)
{
    QUrl proxyUrl = QUrl::fromUserInput(value);

    if (proxyUrl.isValid()) {
        setProxyHost(proxyUrl.host());
        setProxyPort(proxyUrl.port(1080));
    }
}

<<<<<<< HEAD
void Config::setProxyAuth(const QString &value)
=======
bool Config::useProxyForLocalhost() const
{
  return m_useProxyForLocalhost;
}

void Config::setUseProxyForLocalhost(const bool &value) 
{
  m_useProxyForLocalhost = value;
}

void Config::setProxyAuth(const QString& value)
>>>>>>> f3ceb611309760736b317e04bf42a3419e1bbfec
{
    QString proxyUser = value;
    QString proxyPass = "";

    if (proxyUser.lastIndexOf(':') > 0) {
        proxyPass = proxyUser.mid(proxyUser.lastIndexOf(':') + 1).trimmed();
        proxyUser = proxyUser.left(proxyUser.lastIndexOf(':')).trimmed();

        setProxyAuthUser(proxyUser);
        setProxyAuthPass(proxyPass);
    }
}

QString Config::proxyAuth() const
{
    return proxyAuthUser() + ":" + proxyAuthPass();
}

QString Config::proxyAuthUser() const
{
    return m_proxyAuthUser;
}

QString Config::proxyAuthPass() const
{
    return m_proxyAuthPass;
}

QString Config::proxyHost() const
{
    return m_proxyHost;
}

int Config::proxyPort() const
{
    return m_proxyPort;
}

QStringList Config::scriptArgs() const
{
    return m_scriptArgs;
}

void Config::setScriptArgs(const QStringList &value)
{
    m_scriptArgs.clear();

    QStringListIterator it(value);
    while (it.hasNext()) {
        m_scriptArgs.append(it.next());
    }
}

QString Config::scriptEncoding() const
{
    return m_scriptEncoding;
}

void Config::setScriptEncoding(const QString &value)
{
    if (value.isEmpty()) {
        return;
    }

    m_scriptEncoding = value;
}

QString Config::scriptLanguage() const
{
    return m_scriptLanguage;
}

void Config::setScriptLanguage(const QString &value)
{
    if (value.isEmpty()) {
        return;
    }

    m_scriptLanguage = value;
}

QString Config::scriptFile() const
{
    return m_scriptFile;
}

void Config::setScriptFile(const QString &value)
{
    m_scriptFile = value;
}

QString Config::unknownOption() const
{
    return m_unknownOption;
}

void Config::setUnknownOption(const QString &value)
{
    m_unknownOption = value;
}

bool Config::versionFlag() const
{
    return m_versionFlag;
}

void Config::setVersionFlag(const bool value)
{
    m_versionFlag = value;
}

bool Config::debug() const
{
    return m_debug;
}

void Config::setDebug(const bool value)
{
    m_debug = value;
}

int Config::remoteDebugPort() const
{
    return m_remoteDebugPort;
}

void Config::setRemoteDebugPort(const int port)
{
    m_remoteDebugPort = port;
}

bool Config::remoteDebugAutorun() const
{
    return m_remoteDebugAutorun;
}

void Config::setRemoteDebugAutorun(const bool value)
{
    m_remoteDebugAutorun = value;
}

bool Config::webSecurityEnabled() const
{
    return m_webSecurityEnabled;
}

void Config::setWebSecurityEnabled(const bool value)
{
    m_webSecurityEnabled = value;
}

void Config::setJavascriptCanOpenWindows(const bool value)
{
    m_javascriptCanOpenWindows = value;
}

bool Config::javascriptCanOpenWindows() const
{
    return m_javascriptCanOpenWindows;
}

void Config::setJavascriptCanCloseWindows(const bool value)
{
    m_javascriptCanCloseWindows = value;
}

bool Config::javascriptCanCloseWindows() const
{
    return m_javascriptCanCloseWindows;
}

void Config::setWebdriver(const QString &webdriverConfig)
{
    // Parse and validate the configuration
    bool isValidPort;
    QStringList wdCfg = webdriverConfig.split(':');
    if (wdCfg.length() == 1 && wdCfg[0].toInt(&isValidPort) && isValidPort) {
        // Only a PORT was provided
        m_webdriverPort = wdCfg[0];
    } else if(wdCfg.length() == 2 && !wdCfg[0].isEmpty() && wdCfg[1].toInt(&isValidPort) && isValidPort) {
        // Both IP and PORT provided
        m_webdriverIp = wdCfg[0];
        m_webdriverPort = wdCfg[1];
    }
}

QString Config::webdriver() const
{
    return QString("%1:%2").arg(m_webdriverIp).arg(m_webdriverPort);
}

bool Config::isWebdriverMode() const
{
    return !m_webdriverPort.isEmpty();
}

void Config::setWebdriverLogFile(const QString& webdriverLogFile)
{
    m_webdriverLogFile = webdriverLogFile;
}

QString Config::webdriverLogFile() const
{
    return m_webdriverLogFile;
}

void Config::setWebdriverLogLevel(const QString& webdriverLogLevel)
{
    m_webdriverLogLevel = webdriverLogLevel;
}

QString Config::webdriverLogLevel() const
{
    return m_webdriverLogLevel;
}

void Config::setWebdriverSeleniumGridHub(const QString &hubUrl)
{
    m_webdriverSeleniumGridHub = hubUrl;
}

QString Config::webdriverSeleniumGridHub() const
{
    return m_webdriverSeleniumGridHub;
}

// private:
void Config::resetToDefaults()
{
    m_autoLoadImages = true;
    m_cookiesFile = QString();
    m_offlineStoragePath = QString();
    m_offlineStorageDefaultQuota = -1;
    m_diskCacheEnabled = false;
    m_maxDiskCacheSize = -1;
    m_ignoreSslErrors = false;
    m_localToRemoteUrlAccessEnabled = false;
    m_outputEncoding = "UTF-8";
    m_proxyType = "http";
    m_proxyHost.clear();
    m_proxyPort = 1080;
    m_proxyAuthUser.clear();
    m_proxyAuthPass.clear();
    m_scriptArgs.clear();
    m_scriptEncoding = "UTF-8";
    m_scriptLanguage.clear();
    m_scriptFile.clear();
    m_unknownOption.clear();
    m_versionFlag = false;
    m_debug = false;
    m_remoteDebugPort = -1;
    m_remoteDebugAutorun = false;
    m_webSecurityEnabled = true;
    m_javascriptCanOpenWindows = true;
    m_javascriptCanCloseWindows = true;
    m_helpFlag = false;
    m_printDebugMessages = false;
    m_sslProtocol = "sslv3";
    m_sslCertificatesPath.clear();
    m_webdriverIp = QString();
    m_webdriverPort = QString();
    m_webdriverLogFile = QString();
    m_webdriverLogLevel = "INFO";
    m_webdriverSeleniumGridHub = QString();
    m_webdriverSeleniumGridRemoteProxyClass = QString();
}

void Config::setProxyAuthPass(const QString &value)
{
    m_proxyAuthPass = value;
}

void Config::setProxyAuthUser(const QString &value)
{
    m_proxyAuthUser = value;
}

void Config::setProxyHost(const QString &value)
{
    m_proxyHost = value;
}

void Config::setProxyPort(const int value)
{
    m_proxyPort = value;
}

bool Config::helpFlag() const
{
    return m_helpFlag;
}

void Config::setHelpFlag(const bool value)
{
    m_helpFlag = value;
}

bool Config::printDebugMessages() const
{
    return m_printDebugMessages;
}

void Config::setPrintDebugMessages(const bool value)
{
    m_printDebugMessages = value;
}

void Config::handleSwitches()
{
    setHelpFlag(m_parser.isSet(helpOption));
    setVersionFlag(m_parser.isSet(versionOption));

    if (m_parser.isSet(webdriverOption)) {
        setWebdriver(DEFAULT_WEBDRIVER_CONFIG);
    }
}

bool Config::readBooleanValue(const QString& option, const QString &value) const
{
	if ((value != "true") && (value != "yes") && (value != "false") && (value != "no")) {
		throw UnknownOptionException(option);
	}
	return (value == "true") || (value == "yes");
	 
}

<<<<<<< HEAD
    QStringList booleanFlags;
    booleanFlags << "debug";
    booleanFlags << "disk-cache";
    booleanFlags << "ignore-ssl-errors";
    booleanFlags << "load-images";
    booleanFlags << "local-to-remote-url-access";
    booleanFlags << "remote-debugger-autorun";
    booleanFlags << "web-security";
    if (booleanFlags.contains(option)) {
        if ((value != "true") && (value != "yes") && (value != "false") && (value != "no")) {
            setUnknownOption(QString("Invalid values for '%1' option.").arg(option));
            return;
        }
        boolValue = (value == "true") || (value == "yes");
=======
void Config::handleOptions()
{
    if (m_parser.isSet(cookiesFileOption)) {
        setCookiesFile(m_parser.value(cookiesFileOption));
>>>>>>> 20da5b0a41b28bcc3b94ab761150338a59f5b84e
    }

    if (m_parser.isSet(configOption)) {
		loadJsonFile(m_parser.value(configOption));
    }

    if (m_parser.isSet(debugOption)) {
		setPrintDebugMessages(readBooleanValue(debugOption.valueName(), m_parser.value(debugOption)));
    }

	if (m_parser.isSet(diskCacheOption)) {
		setDiskCacheEnabled(readBooleanValue(diskCacheOption.valueName(), m_parser.value(diskCacheOption)));
	}
    
	if (m_parser.isSet(ignoreSslErrorsOption)) {
        setIgnoreSslErrors(readBooleanValue(ignoreSslErrorsOption.valueName(), m_parser.value(ignoreSslErrorsOption)));
    }

	if (m_parser.isSet(loadImagesOption)) {
        setAutoLoadImages(readBooleanValue(loadImagesOption.valueName(), m_parser.value(loadImagesOption)));
    }

	if (m_parser.isSet(localStoragePathOption)) {
		setOfflineStoragePath(m_parser.value(localStoragePathOption));
    }

	if (m_parser.isSet(localStorageQuotaOption)) {
		setOfflineStorageDefaultQuota(m_parser.value(localStorageQuotaOption).toInt());
    }

	if (m_parser.isSet(localUrlAccessOption)) {
        setLocalUrlAccessEnabled(readBooleanValue(localUrlAccessOption.valueName(), m_parser.value(localUrlAccessOption)));
    }

	if (m_parser.isSet(localToRemoteUrlAccessOption)) {
        setLocalToRemoteUrlAccessEnabled(readBooleanValue(localToRemoteUrlAccessOption.valueName(), m_parser.value(localToRemoteUrlAccessOption)));
    }

<<<<<<< HEAD
    if (option == "local-to-remote-url-access") {
        setLocalToRemoteUrlAccessEnabled(boolValue);
=======
	if (m_parser.isSet(maxDiskCacheSizeOption)) {
		setMaxDiskCacheSize(m_parser.value(maxDiskCacheSizeOption).toInt());
    }

	if (m_parser.isSet(outputEncodingOption)) {
		setOutputEncoding(m_parser.value(outputEncodingOption));
>>>>>>> 20da5b0a41b28bcc3b94ab761150338a59f5b84e
    }

	if (m_parser.isSet(remoteDebuggerAutorunOption)) {
        setRemoteDebugAutorun(readBooleanValue(remoteDebuggerAutorunOption.valueName(), m_parser.value(remoteDebuggerAutorunOption)));
    }

	if (m_parser.isSet(remoteDebuggerPortOption)) {
        setDebug(true);
		setRemoteDebugPort(m_parser.value(remoteDebuggerPortOption).toInt());
    }

	if (m_parser.isSet(proxyOption)) {
		setProxy(m_parser.value(proxyOption));
    }

	if (m_parser.isSet(proxyTypeOption)) {
		setProxyType(m_parser.value(proxyTypeOption));
    }

	if (m_parser.isSet(proxyAuthOption)) {
        setProxyAuth(m_parser.value(proxyAuthOption));
    }

	if (m_parser.isSet(scriptEncodingOption)) {
		setScriptEncoding(m_parser.value(scriptEncodingOption));
    }

	if (m_parser.isSet(scriptLanguageOption)) {
		setScriptLanguage(m_parser.value(scriptLanguageOption));
    }

	if (m_parser.isSet(webSecurityOption)) {
        setWebSecurityEnabled(readBooleanValue(webSecurityOption.valueName(), m_parser.value(webSecurityOption)));
    }

	if (m_parser.isSet(sslProtocolOption)) {
		setSslProtocol(m_parser.value(sslProtocolOption));
    }

	if (m_parser.isSet(sslCiphersOption)) {
		setSslCiphers(m_parser.value(sslCiphersOption));
    }
<<<<<<< HEAD
    if (option == "ssl-protocol") {
        setSslProtocol(value.toString());
    }
    if (option == "ssl-certificates-path") {
        setSslCertificatesPath(value.toString());
=======

	if (m_parser.isSet(sslCertificatesPathOption)) {
		setSslCertificatesPath(m_parser.value(sslCertificatesPathOption));
>>>>>>> 20da5b0a41b28bcc3b94ab761150338a59f5b84e
    }

    if (m_parser.isSet(webdriverAddressOption) ) {
		setWebdriver(m_parser.value(webdriverAddressOption));
    }

    if (m_parser.isSet(webdriverLogfileOption)) {
        setWebdriverLogFile(m_parser.value(webdriverLogfileOption));
    }

    if (m_parser.isSet(webdriverLogLevelOption)) {
        setWebdriverLogLevel(m_parser.value(webdriverLogLevelOption));
    }

    if (m_parser.isSet(webdriverSeleniumGridHubOption)) {
        setWebdriverSeleniumGridHub(m_parser.value(webdriverSeleniumGridHubOption));
    }
    if (option == "webdriver-selenium-grid-remote-proxy-class") {
        setWebdriverSeleniumGridRemoteProxyClass(value.toString());
    }
}

void Config::handleParams()
{
	QStringList positionalArguments = m_parser.positionalArguments();

	if (!positionalArguments.isEmpty()) {
		m_scriptFile = positionalArguments.takeFirst();
	}

	if (!positionalArguments.isEmpty()) {
		m_scriptArgs += positionalArguments;
	}
}

void Config::handleError(const QString &error)
{
    setUnknownOption(QString("Error: %1").arg(error));
}

QString Config::sslProtocol() const
{
    return m_sslProtocol;
}

void Config::setSslProtocol(const QString& sslProtocolName)
{
    m_sslProtocol = sslProtocolName.toLower();
}

QString Config::sslCertificatesPath() const
{
    return m_sslCertificatesPath;
}

void Config::setSslCertificatesPath(const QString& sslCertificatesPath)
{
    QFileInfo sslPathInfo = QFileInfo(sslCertificatesPath);
    if (sslPathInfo.isDir()) {
        if (sslCertificatesPath.endsWith('/'))
            m_sslCertificatesPath = sslCertificatesPath + "*";
        else
            m_sslCertificatesPath = sslCertificatesPath + "/*";
    } else {
        m_sslCertificatesPath = sslCertificatesPath;
     }
}

void Config::setWebdriverSeleniumGridRemoteProxyClass(const QString& webdriverSeleniumGridRemoteProxyClass)
{
    m_webdriverSeleniumGridRemoteProxyClass = webdriverSeleniumGridRemoteProxyClass;
}

QString Config::webdriverSeleniumGridRemoteProxyClass() const
{
	// TODO:: Self contained
    return m_webdriverSeleniumGridRemoteProxyClass;
}
