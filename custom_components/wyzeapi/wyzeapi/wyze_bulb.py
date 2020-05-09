import asyncio

from .wyze_device import *

class WyzeBulb(WyzeDevice):
    def __init__(self, api, device_mac, friendly_name, state, device_model):
        super().__init__(api, device_mac, friendly_name, state, device_model)
        self._brightness = self._colortemp = None

    async def async_turn_on(self):
        if self._colortemp is not None or self._brightness is not None:
            url = 'https://api.wyzecam.com/app/v2/device/set_property_list'

            property_list = [{"pid": "P3", "pvalue": "1"}]

            if self._brightness:
                brightness = self.translate(self._brightness, 1, 255, 1, 100)
                property_list.append({"pid": "P1501", "pvalue": brightness})

            if self._colortemp:
                colortemp = self.translate(self._colortemp, 500, 140, 2700, 6500)
                property_list.append({"pid": "P1502", "pvalue": colortemp})

            payload = {
                "phone_id": self._api._device_id,
                "property_list": property_list,
                "device_model": self._device_model,
                "app_name": "com.hualai.WyzeCam",
                "app_version": "2.6.62",
                "sc": "01dd431d098546f9baf5233724fa2ee2",
                "sv": "a8290b86080a481982b97045b8710611",
                "device_mac": self._device_mac,
                "app_ver": "com.hualai.WyzeCam___2.6.62",
                "ts": "1575951274357",
                "access_token": self._api._access_token
            }

        else:
            url = 'https://api.wyzecam.com/app/v2/device/set_property'

            payload = {
                'phone_id': self._api._device_id,
                'access_token': self._api._access_token,
                'device_model': self._device_model,
                'ts': '1575948896791',
                'sc': '01dd431d098546f9baf5233724fa2ee2',
                'sv': '107693eb44244a948901572ddab807eb',
                'device_mac': self._device_mac,
                'pvalue': "1",
                'pid': 'P3',
                'app_ver': 'com.hualai.WyzeCam___2.6.62'
            }

        loop = asyncio.get_running_loop()
        loop.create_task(self._api.async_do_request(url, payload))

        self._state = True
        self._just_changed_state = True
    
    async def async_update(self):
        if self._just_changed_state:
            self._just_changed_state = False
        else:
            url = "https://api.wyzecam.com/app/v2/device/get_property_list"

            payload = {
                "target_pid_list":[],
                "phone_id": self._api._device_id,
                "device_model": self._device_model,
                "app_name":"com.hualai.WyzeCam",
                "app_version":"2.6.62",
                "sc":"01dd431d098546f9baf5233724fa2ee2",
                "sv":"22bd9023a23b4b0b9977e4297ca100dd",
                "device_mac": self._device_mac,
                "app_ver":"com.hualai.WyzeCam___2.6.62",
                "phone_system_type":"1",
                "ts":"1575955054511",
                "access_token": self._api._access_token
            }

            data = await self._api.async_do_request(url, payload)

            for item in data['data']['property_list']:
                if item['pid'] == "P3":
                    self._state = True if int(item['value']) == 1 else False
                elif item['pid'] == "P5":
                    self._avaliable = False if int(item['value']) == 0 else True
                elif item['pid'] == "P1501":
                    self._brightness = self.translate(int(item['value']), 0, 100, 0, 255)
                elif item['pid'] == "P1502":
                    self._colortemp = self.translate(int(item['value']), 2700, 6500, 500, 153)

    def translate(self, value, leftMin, leftMax, rightMin, rightMax):
        # Figure out how 'wide' each range is
        leftSpan = leftMax - leftMin
        rightSpan = rightMax - rightMin

        # Convert the left range into a 0-1 range (float)
        valueScaled = float(value - leftMin) / float(leftSpan)

        # Convert the 0-1 range into a value in the right range.
        return rightMin + (valueScaled * rightSpan)
