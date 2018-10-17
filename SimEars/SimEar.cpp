/*======================================================================================================================

    Copyright 2011, 2012, 2013, 2014, 2015 Institut fuer Neuroinformatik, Ruhr-Universitaet Bochum, Germany

    This file is part of cedar.

    cedar is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License as published by the
    Free Software Foundation, either version 3 of the License, or (at your
    option) any later version.

    cedar is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
    License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with cedar. If not, see <http://www.gnu.org/licenses/>.

========================================================================================================================

    Institute:   Ruhr-Universitaet Bochum
                 Institut fuer Neuroinformatik

    File:        EarSubscriber.h

    Maintainer:  Tutorial Writer Person
    Email:       cedar@ini.rub.de
    Date:        2011 12 09

    Description:

    Credits:

======================================================================================================================*/

// CEDAR INCLUDES
#include "SimEar.h"
#include <cedar/processing/ExternalData.h> // getInputSlot() returns ExternalData
#include <cedar/auxiliaries/MatData.h> // this is the class MatData, used internally in this step
#include "cedar/auxiliaries/math/functions.h"

// SYSTEM INCLUDES

//----------------------------------------------------------------------------------------------------------------------
// constructors and destructor
//----------------------------------------------------------------------------------------------------------------------
SimEar::SimEar()
:
cedar::proc::Step(true),
mOutput(new cedar::aux::MatData(cv::Mat::zeros(1, 50, CV_32F))),
mLevel(new cedar::aux::DoubleParameter(this,"Motor Pos",25))
{
this->declareOutput("demo_output", mOutput);
this->declareInput("motorLeft", true);
this->declareInput("motorRight",true);

mGaussMatrixSizes.push_back(50);
mGaussMatrixSigmas.push_back(3.0);
mGaussMatrixCenters.push_back(25.0);
//init the variable that will get the sensor value
dat = 0;

this->connect(this->mLevel.get(), SIGNAL(valueChanged()), this, SLOT(reCompute()));

}
//----------------------------------------------------------------------------------------------------------------------
// methods
//----------------------------------------------------------------------------------------------------------------------
void SimEar::compute(const cedar::proc::Arguments&)
{

   cedar::aux::ConstDataPtr op1 = this->getInputSlot("motorLeft")->getData();
   cedar::aux::ConstDataPtr op2 = this->getInputSlot("motorRight")->getData();
   cv::Mat doublepos = op1->getData<cv::Mat>();
   cv::Mat doublepos2 = op2->getData<cv::Mat>();
   float t1 = doublepos.at<float>(0);
   float t2 = doublepos2.at<float>(0);
   activatedLeft = static_cast<double> (t1);
   activatedRight = static_cast<double> (t2);
   activatedLeft = round(activatedLeft);
   activatedRight = round(activatedRight);
   std::cout<<"Left : "<<activatedLeft<<"/n";
   std::cout<<"Right : "<<activatedRight<<"/n";
   //change the Gaussian function with the value of the ear sensor.
   //this->mOutput->setData(cedar::aux::math::gaussMatrix(1,mGaussMatrixSizes,dat,mGaussMatrixSigmas,mGaussMatrixCenters,true));


}

void SimEar::reCompute()
{
   dat = static_cast<double>(this->mLevel->getValue());
}

void SimEar::reset()
{

	//ros::shutdown();

}
