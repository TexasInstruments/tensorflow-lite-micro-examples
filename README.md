# TensorFlow Lite Micro Examples for TI devices

This repository contains TF-Lite Micro examples for several TI devices, as listed below.


## Build Status

|   Build Type  |  Status  |
| -----------   |  --------- |
| Sync from tflite-micro | [![Sync from tflite-micro](https://github.com/TexasInstruments/tensorflow-lite-micro-examples/actions/workflows/sync.yml/badge.svg)](https://github.com/TexasInstruments/tensorflow-lite-micro-examples/actions/workflows/sync.yml)
| Build (Windows)  | [![TI](https://github.com/TexasInstruments/tensorflow-lite-micro-examples/actions/workflows/ci.yml/badge.svg?event=status)](https://github.com/TexasInstruments/tensorflow-lite-micro-examples/actions/workflows/ci.yml)


## Table of contents

-   [Deploy to MSP432P401R](#deploy-to-msp432p401r)
-   [Deploy to CC32XXSF](#deploy-to-cc32xxsf)


## Deploy to MSP432P401R
General hardware requirements:
1. Development kit: TI MSP432P4R01 LaunchPad

Micro Speech example hardware requirements:
1. Add-on board: TI BOOSTXL-AUDIO

Software requirements:
1. Download and install Code Composer Studio 11+ ([instructions](http://software-dl.ti.com/ccs/esd/documents/users_guide/ccs_installation.html#))
    - See section 3.2.3.5. Device Support - when prompted select "SimpleLink MSP432 low power + performance MCUs" component before proceeding
2. Download and install the latest **MSP432P401R** SDK ([instructions](https://www.ti.com/tool/download/SIMPLELINK-MSP432-SDK))
3. Install the GCC toolchain
    1. Launch Code Composer Studio
    2. When prompted for a workspace directory, provide a new directory name to create a new workspace (or select an existing workspace directory), and press "Launch"  - after which the main IDE windows will become visible
    3. Go to the Help menu and select - Install GCC ARM Compiler Tools… -> a window titled "Install" will open
    - On the bottom, uncheck "Show only the latest versions of available software"
    - In the middle, expand the "ARM GCC Tools" tree
    - Check "ARM GCC Compiler Tools" - Version: "9.2.1.2009-q4-major"
    - Press the "Next" button to finish the installation
    - Restart Code Composer Studio


Generate, build and flash the project:

1. Launch Code Composer Studio
2. When prompted for a workspace directory, provide a new directory name to create a new workspace (or select an existing workspace directory), and press "Launch"  - after which the main IDE windows will become visible
3. In the main menu, choose Tools->Import CCS Projects...
4. In the "Import CCS Projects" dialog, put the path to the repository in the "Select search-directory" field with the correct target - e.g. ~/repos/tensorflow-lite-micro-examples/targets/MSP432R01
5. The "Discovery Projects" list should become populated with the available projects
6. Choose a project and click the "Finish" button

Build and Flash:

In Code Composer Studio, select Run->Debug
 - CCS will build the project and flash it to the device
 - When flasing is done, select Run->Terminate
 - Reset the board manually
 
    
Do the following to display the program output (per your computer OS):
 - Linux
    - Execute the following command in a terminal
        ```
        screen /dev/ttyACM0 115200
        ```
 - Windows
    - Open "Device Manager" to determine the COM port name, the device is called "XDS110 Class Application/User UART (COM#)"
    - Use a serial terminal emulator to display the output (e.g. TeraTerm, PuTTy, etc)

   



## Deploy to CC32XXSF
General hardware requirements:
1. Development kit: TI MSP432P4R01 LaunchPad

Micro Speech example hardware requirements:
1. Add-on board: TI BOOSTXL-AUDIO

Software requirements:
1. Download and install Code Composer Studio 11+ ([instructions](http://software-dl.ti.com/ccs/esd/documents/users_guide/ccs_installation.html#))
    - See section 3.2.3.5. Device Support - when prompted select "SimpleLink Wi-Fi CC32xx Wireless MCUs" component before proceeding
2. Download and install the latest **CC32XX** SDK ([instructions](https://www.ti.com/tool/SIMPLELINK-CC32XX-SDK))
3. Install the GCC toolchain
    1. Launch Code Composer Studio
    2. When prompted for a workspace directory, provide a new directory name to create a new workspace (or select an existing workspace directory), and press "Launch" - after which the main IDE windows will become visible
    3. Go to the Help menu and select - Install GCC ARM Compiler Tools… -> a window titled "Install" will open
    - On the bottom, uncheck "Show only the latest versions of available software"
    - In the middle, expand the "ARM GCC Tools" tree
    - Check "ARM GCC Compiler Tools" - Version: "9.2.1.2009-q4-major"
    - Press the "Next" button to finish the installation
    - Restart Code Composer Studio


Generate, build and flash the project:

1. Launch Code Composer Studio
2. When prompted for a workspace directory, provide a new directory name to create a new workspace (or select an existing workspace directory), and press "Launch"  - after which the main IDE windows will become visible
3. In the main menu, choose Tools->Import CCS Projects...
4. In the "Import CCS Projects" dialog, put the path to the repository in the "Select search-directory" field with the correct target - e.g. ~/repos/tensorflow-lite-micro-examples/targets/CC32XXSF
5. The "Discovery Projects" list should become populated with the available projects
6. Choose a project and click the "Finish" button

Build and Flash:

In Code Composer Studio, select the project in the Project Explorer (left side pane)
 - Build
    - Go to the "Project" menu and select "Build Project"
 - Flash
    - Go to the "Run" menu, select "Load"->"Load SLI Image to Serial Flash"
 - Reset the board manually
 
    
Do the following to display the program output (per your computer OS):
 - Linux
    - Execute the following command in a terminal
        ```
        screen /dev/ttyACM0 115200
        ```
 - Windows
    - Open "Device Manager" to determine the COM port name, the device is called "XDS110 Class Application/User UART (COM#)"
    - Use a serial terminal emulator to display the output (e.g. TeraTerm, PuTTy, etc)
