#include <iostream>
#include "repairOBJFile.hpp"

//Eigen
#include <Eigen/Eigen>

//libigl
#include <igl/readOBJ.h>
#include <igl/readOFF.h>
#include <igl/opengl/glfw/Viewer.h>

void printUsage(char** &argv){
    std::cout << "Usage:" << std::endl;
    std::cout << argv[0] << " [Mesh_File]" << std::endl;
}

int main(int argc, char** argv){
    if (argc != 2 or argv[1] == "-h"){
        printUsage(argv);
        return -1;
    }
    //repair input file
    std::string in_ = argv[1];
    std::string out_ = in_.substr(0, in_.size()-4) + "_fixed.obj";
    RepairOBJFile::repair(in_, out_);



    //Read file
    Eigen::MatrixXd V;
    Eigen::MatrixXi F;
    igl::readOBJ(out_, V,F);


    //Create Viewer
    igl::opengl::glfw::Viewer viewer;


    //Add Data to Viewer
    viewer.data().set_mesh(V, F);
    viewer.data().show_lines = false;

    //Show Viewer
    viewer.launch();
}
