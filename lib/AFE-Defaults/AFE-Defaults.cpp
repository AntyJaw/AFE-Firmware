#include "AFE-Defaults.h"                                                                                                                                       

AFEDefaults::AFEDefaults(){}

void AFEDefaults::set() {

  AFEDataAccess *Data;

  NETWORK networkConfiguration;
  FIRMWARE firmwareConfiguration;
  MQTT MQTTConfiguration;
  DOMOTICZ DomoticzConfiguration;
  RELAY RelayConfiguration;
  SWITCH SwitchConfiguration;
  DS18B20 DS18B20Configuration;
  LED LEDConfiguration;

  sprintf(networkConfiguration.ssid, "POLICJA: Posterunek");
  sprintf(networkConfiguration.password, "1231231234");
  sprintf(networkConfiguration.host, "AFE-Device");
  networkConfiguration.isDHCP = true;
  networkConfiguration.ip = IPAddress(0, 0, 0, 0);
  networkConfiguration.gateway = IPAddress(0, 0, 0, 0);
  networkConfiguration.subnet = IPAddress(255, 255, 255, 0);
  networkConfiguration.noConnectionAttempts = 20;
  networkConfiguration.waitTimeConnections = 1;
  networkConfiguration.waitTimeSeries = 60;

  Serial << endl << "INFO: Setting defaults: firmware";

  sprintf(firmwareConfiguration.version, "1.0.5");
  firmwareConfiguration.type = 0;
  firmwareConfiguration.autoUpgrade = 0;
  sprintf(firmwareConfiguration.upgradeURL, "http://api.czabanowski.com");

  Serial << endl << "INFO: Setting defaults: mqtt";

  /* @TODO Only for MQTT */
  sprintf(MQTTConfiguration.host, "");
  MQTTConfiguration.ip = IPAddress(0, 0, 0, 0);
  sprintf(MQTTConfiguration.user, "");
  sprintf(MQTTConfiguration.password, "");
  MQTTConfiguration.port = 1833;
  sprintf(MQTTConfiguration.topic, "/afedevice/");

  Serial << endl << "INFO: Setting defaults: domoticz";

  /* @TODO Only for Domoticz */
  sprintf(DomoticzConfiguration.host, "");
  DomoticzConfiguration.ip = IPAddress(0, 0, 0, 0);
  sprintf(DomoticzConfiguration.user, "");
  sprintf(DomoticzConfiguration.password, "");
  DomoticzConfiguration.port = 8080;

  Serial << endl << "INFO: Setting defaults: relay";

  RelayConfiguration.present = true;
  RelayConfiguration.gpio = 12;
  RelayConfiguration.timeToOff = 0;
  RelayConfiguration.statePowerOn = 2;
  /* @TODO Only for MQTT */
  RelayConfiguration.stateMQTTConnected = 0;
  sprintf(RelayConfiguration.name, "relay");
  /* @TODO Only for Domoticz
  RelayConfiguration.idx = 0;
  RelayConfiguration.publishToDomoticz = false;
  */

  Serial << endl << "INFO: Setting defaults: switch";

  SwitchConfiguration.present = true;
  SwitchConfiguration.gpio = 0;
  SwitchConfiguration.type = 0;
  SwitchConfiguration.sensitiveness = 0;
  SwitchConfiguration.functionality = 0;

  Serial << endl << "INFO: Setting defaults: ds18b20";

  DS18B20Configuration.present = false;
  DS18B20Configuration.gpio = 0;
  DS18B20Configuration.correction = 0;
  DS18B20Configuration.interval = 60;
  DS18B20Configuration.unit = 0;

  Serial << endl << "INFO: Setting defaults: LED";

  LEDConfiguration.present = true;
  LEDConfiguration.gpio = 13;

  Serial << endl << "INFO: Setting defauls: saving...";

  /* Saving data */
  Data->saveConfiguration(networkConfiguration);
  Data->saveConfiguration(firmwareConfiguration);
  /* @TODO Only for MQTT */
  Data->saveConfiguration(MQTTConfiguration);
  /* @TODO Only for Domoticz
  Data->saveConfiguration(DomoticzConfiguration);
  */
  Data->saveConfiguration(0, RelayConfiguration);
  Data->saveConfiguration(0, SwitchConfiguration);
  Data->saveConfiguration(DS18B20Configuration);
  Data->saveConfiguration(LEDConfiguration);

  Data->saveDeviceMode(2);
  Data->saveRelayState(0, false);
  Data->saveLanguage(0);
}
