#include <FA/FAScene.h>
#include <FA/FAEngine.h>

FAScene::FAScene() {
	//Default stuff
	// FARenderPass *defaultPass = new FAMainRenderPass();
    // FARenderPass *shadow = new FACSMRenderPass();
	// renderPasses = new FARenderPass*[1];
	// renderPasses[0] = defaultPass;
    // renderPasses[0] = shadow;
    // defaultPass->setCB(this);
    // shadow->setCB(this);
	// this->numberOfPasses = 1;
	this->isActive = true;
	// this->models = new std::vector<FAModel *>();
	//User stuff
}

// void FAScene::render() {
	// for (int i = 0; i < numberOfPasses; i++) {
	// 	renderPasses[i]->render();
	// }
// 	// m->render(camera);
// }

void FAScene::onInit() {

    // displayFps = true;
    // children = new FANode();
    // camera = new FACamera();

    // font = new FAFont("Helvetica.ttf", 15, windowWidth, windowHeigth);
    // fpsText = new FAText2D(font);
    // fpsText->setShader(shaders->getShader("Text2D"));
    // fpsText->setText("fps: 60");
    // fpsText->setPos(glm::vec3(-0.99,0.95,0));
    // fpsText->setColor(FAColorWhite);
    // addHUDElement(fpsText);

    // vertexCountText = new FAText2D(font);
    // vertexCountText->setShader(shaders->getShader("Text2D"));
    // vertexCountText->setText("Vertices: 0");
    // vertexCountText->setPos(glm::vec3(-0.99,0.9,0));
    // vertexCountText->setColor(FAColorWhite);
    // addHUDElement(vertexCountText);

    this->init();
}

void FAScene::onUpdate(float dt) {
    if (!isActive) {
        return;
    }
    // rootNode.update(dt);
    // if (displayFps) {
    //     if (time > 1) {
    //         fpsText->setText("fps: " + std::to_string((frames/time)));
    //         frames = 0;
    //         time = 0;
    //     } else {
    //         time+=dt;
    //         frames++;
    //     }
    //     vertexCountText->setText("vertices: " + std::to_string(children->getVertexCount()));
    // }
    update(dt);
    // for (FAHUDElement *element : HUDElements) {
    //     element->onUpdate(dt);
    // }
}

void FAScene::onRender() {
	// if (!isActive) return;
  //   camera->useView();
	// for (int i = 0; i < numberOfPasses; i++) {
  //       renderPasses[i]->render();
  //   }
	// this->render();
  //   glClear(GL_DEPTH_BUFFER_BIT);
  //   for (FAHUDElement *element : HUDElements) {
  //       element->onRender();
  //   }
}

// void FAScene::addChild(FANode *child) {
// 	rootNode.addChild(child);
// 	if (FAModel *model = dynamic_cast<FAModel *>(child)) {
//         for (FAMaterialComponent *component : requiredComponents) {
//             model->addMaterialComponent(component);
//         }
// 		models.push_back(model);
// 	} else if (FALight *light = dynamic_cast<FALight *>(child)) {
//         lights.push_back(light);
//         for (FARenderPass *pass : *light->getRequirements()) {
//             addRenderPass(pass);
//         }
//         for (FAModel *model : models) {
//             for (FAMaterialComponent *component : *light->getMaterialRequirements()) {
//                 model->addMaterialComponent(component);
//                 requiredComponents.push_back(component);
//             }
//         }
//     } else if (FAHUDElement *element = dynamic_cast<FAHUDElement *>(child)) {
//         HUDElements.push_back(element);
//     } else {
//         std::cout << "Added unknow type as child of FAScene" << std::endl;
//     }
// }

// void FAScene::addRenderPass(FARenderPass *renderPass) {
//     std::cout << "adding renderPass!" << std::endl;
// 	this->numberOfPasses++;
//     renderPass->setCB(this);
// 	FARenderPass **temp = new FARenderPass*[this->numberOfPasses];
// 	for (int i = 0; i < this->numberOfPasses-1; i++) {
// 		if (renderPass->getPriority() < renderPasses[i]->getPriority()) {
//             temp[i] = renderPass;
//             renderPass = renderPasses[i];
//         } else {
//             temp[i] = renderPasses[i];
//         }
// 	}
// 	temp[this->numberOfPasses-1] = renderPass;
// 	delete[] renderPasses;
// 	renderPasses = temp;
// }

void FAScene::setCallback(FAEngine *_callback) {
    this->callback = _callback;
}

void FAScene::setWindowSize(int width, int height) {
    this->windowWidth = width;
    this->windowHeigth = height;
}

// void FAScene::setCursorState(int state) {
//     this->callback->setCursorState(state);
// }

// void FAScene::getMouseKeyInput(int button, int action) {
    //TODO
    // print(lastCursorPosition);
    // if (true) {
        // if (button == GLFW_MOUSE_BUTTON_1) {
        //     if (action == GLFW_PRESS) {
        //         for (FAHUDElement *node : HUDElements) {
        //             if (node->handleClick(lastCursorPosition)) {
        //                 buttonPressed(node);
        //                 return;
        //             }
        //         }
        //     }
        // }
    // }
    // mouseKeyInput(button, action);
// }

// void FAScene::getCursorPosition(double x, double y) {
//     // lastCursorPosition = glm::vec2(x/windowWidth,y/windowHeigth);
//     cursorPosition(x, y);
// }

// int FAScene::getCursorState() {
//     return callback->getCursorState();
// }

// std::vector<FAModel *> *FAScene::getModels() {
// 	return &this->models;
// }

// FACamera *FAScene::getCamera() {
// 	return (this->camera);
// }

float FAScene::getWindowWidths() {
    return this->windowWidth;
}

FAScene::~FAScene() {

}
