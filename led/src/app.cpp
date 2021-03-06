/*
 * Copyright (c) 2011, 2012 Research In Motion Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/device/Led>

#include "app.hpp"

using namespace bb::cascades;

App::App()
{
	// Register our class that wraps the C++ Led interface with QML so that we
	// can make calls into the Led and get results, through QML.
    qmlRegisterType<bb::device::Led>("bb.device", 1, 0, "Led");
    qmlRegisterUncreatableType<bb::device::LedColor>("bb.device", 1, 0, "LedColor", "");

    // Here we create a QMLDocument and load it, we are using build patterns.
    QmlDocument *qml = QmlDocument::create("main.qml");
    qml->setContextProperty("cs", this);

    // The application AbstractPane is created from QML.
    AbstractPane *root = qml->createRootNode<AbstractPane>();

    // Finally the main scene for the application is set.
    Application::setScene(root);
}
