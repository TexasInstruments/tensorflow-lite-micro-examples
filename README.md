## Table of contents

-   [Getting started](#getting-started)
-   [Deploy to MSP432P401R](#deploy-to-msp432p401r)

|   Build Type  |  Status  |
| -----------   |  --------- |
| Sync from tflite-micro | [![Sync from tflite-micro](https://github.com/TexasInstruments/tensorflow-lite-micro-examples/actions/workflows/sync.yml/badge.svg)](https://github.com/TexasInstruments/tensorflow-lite-micro-examples/actions/workflows/sync.yml)
| CCS on Linux  | [![TI](https://github.com/TexasInstruments/tensorflow-lite-micro-examples/actions/workflows/ci.yml/badge.svg?event=status)](https://github.com/TexasInstruments/tensorflow-lite-micro-examples/actions/workflows/ci.yml)


## Getting Started

## Deploy to MSP432P401R
General Hardware requirements:
1. Development kit: TI MSP432P4R01 LaunchPad

Micro Speech Example
1. Add-on board: TI BOOSTXL-AUDIO

Software requirements:
1. Download and install Code Composer Studio 10+ ([instructions](http://software-dl.ti.com/ccs/esd/documents/users_guide/ccs_installation.html#))
    - See section 3.2.3.5. Device Support - when prompted select "SimpleLink MSP432 low power + performance MCUs" component before proceeding
2. Download and install the latest **MSP432P401R** SDK ([instructions](http://www.ti.com/tool/SIMPLELINK-MSP432-SDK))

Generate, build and flash the project:

1. Launch Code Composer Studio
2. When prompted for a workspace directory, choose an existing or a new diretory name - afterwhich the main IDE windows will be visible
3. In the main menu, choose Tools->Import CCS Projects...
4. In the "Import CCS Projects" dialogue, put the path to the repository in the "Select search-directory" field with the correct target - e.g. ~/repos/tensorflow-lite-micro-examples/targets/MSP432R01
5. The "Discovery Projects" list should become populated with the available projects
6. Choose a project an click the "Finish" button

- Build and Flash:

In Code Composer Studio, select Run->Debug
 - CCS will build the project and flash it to the device
 - When flasing is done, select Run->Terminate
 - Reset the board manually
 
    
Use the following commnad to display the program output:
    ```
    screen /dev/ttyACM0 115200
    ```
    The program will also turn toggle a green/red LED when detecting "yes"/"no" respectively.
