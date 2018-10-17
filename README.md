# A ROS Subscriber in Cedar
This is a DFT plugin to simulate Noise Sensor Input inside Cedar.

Everything you want to know about DFT -> https://dynamicfieldtheory.org/

Cedar is the C++ Framework implementing the concepts of DFT -> https://cedar.ini.rub.de/

Everything you need to know about ROS -> http://www.ros.org/

## Getting Started

The plugin is a basic Gaussian Function that takes a 0D node as input. If there is activation, the gaussian function adapt its input.

This plugin is made to close the sensorimotor loop between the ears and the head motors command.

The code work for the 6.x version of Cedar.


### Prerequisites

You first need to install cedar by following the instructions here : https://cedar.ini.rub.de/tutorials/installing_and_running_cedar/

You can't use a precompiled version of Cedar to compile and run the plugin.

I suggest reading about how to create a plugin in Cedar first, it will greatly help to understand how it works : https://cedar.ini.rub.de/tutorials/writing_custom_code_for_cedar/

Install ROS : http://wiki.ros.org/ROS/Installation

The code was tested on ROS Kinetic Kame and Melodic Morenia

**Warning**

ROS and Cedar are a bit to powerful to run on the same computer (if you have a big DFT model and a complex robot), so I recommend using 2 different computer.

### Installing

First clone the repository :

`git clone https://github.com/rouzinho/EarListenerDft.git`

In the project.conf, change the CEDAR_HOME directory to your own :

`set(CEDAR_HOME "your_own_cedar_repository")`

Then create a build repository and prepare the environment for the compilation :

`mkdir build`

`cd build`

`cmake ..`

Finally start the compilation :

`make`

You should see the plugin under the name libEarListener.so in the build/ repository

## Before Running the plugin

Start a ROS Init() Thread : https://github.com/rouzinho/RosInitCedar

## Run the plugin

Execute cedar and load it into cedar 

*Tools -> Manage plugins*

In the plugin Manager window, click on *add* and choose the plugin libEarListener.so. This one should appear in the window.

You can close the window. The plugin is loaded inside cedar and before loading it, make sure your ROS node is running.

You can now go back to the cedar main interface and click on the Utilities tab.

Drag the EarSubscriber widget into the architecture panel. When your architecture is ready, you can start the simulation.
You will see that the EarSubscriber transform the input of a topic into a 1D Gaussian function.
For this case, I read data from a noise sensor and use the value as amplitude of the gaussian function.


## Work in progress

In the future, the plugin will use the Qt widget interface to select the nodes, topics and types in order to avoid changing the code everytime you want to subscribe to a topic.

The plugin will be more like an artefact binding sensors to DFT.



## Authors

Quentin Houbre - Tampere University of Technology

## License

This project is licensed under the BSD licence

