# MenuReloadPlugin
A tiny plugin to quickly reload the Wii U menu.

## Installation
(`[ENVIRONMENT]` is a placeholder for the actual environment name.)

1. Download the [latest version](https://github.com/SuperDude88/MenuReloadPlugin/releases/latest) of this plugin.
2. Extract the file `menureload.wps` into `sd:/wiiu/environments/[ENVIRONMENT]/plugins`.
3. Requires the [WiiUPluginLoaderBackend](https://github.com/wiiu-env/WiiUPluginLoaderBackend) in `sd:/wiiu/environments/[ENVIRONMENT]/modules`.

## Usage

Hold `L3 + R3 + ZL` (press the sticks) to reload the menu and refresh any new or changed apps.

Hold `L3 + R3 + L + R` to do a full restart. Takes longer than a reload, but also refreshes plugins.

## Building

For building you need:

- [wups](https://github.com/wiiu-env/WiiUPluginSystem)
- [wut](https://github.com/devkitPro/wut)

This can be set up automatically using the Dockerfile:
```
# Build docker image (only needed once)
docker build . -t menureload-builder

# Compile to .wps
docker run -v "$(pwd):/src" menureload-builder
```
