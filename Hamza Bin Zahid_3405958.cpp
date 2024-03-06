/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Hamza Bin Zahid
//Matriculation Number: 3405958

#include <iostream>
#include <cmath>
using namespace std;

int main() 

{
    // Initial guess as given in problem
    double x = 0.1;
    double y = 0.1;
    cout << "Initial Values for x is " <<   x <<  endl;
    cout << "Initial Values for y is " <<   y <<  endl;
    
    // Defining maxIterations as given is 11 in question
    const int maxIterations = 11;
    cout << "Iteration x y Norm" << endl;

    // Loop for iterations till maximum 11
    for (int i = 0; i < maxIterations; ++i) 
    {
        // Equations and their derivatives
        double f1 = x * x + y * y - 9; //defining funcion "F1(x)""
        double f2 = x + 2 * y - 6; //defining funcion "F2(x)""
        double df1dx = 2 * x; //defining partial derivative of funcion "F1(x)"" wrt "x"
        double df1dy = 2 * y; //defining partial derivative of funcion "F1(x)"" wrt "y"
        double df2dx = 1; //defining partial derivative of funcion "F2(x)" wrt "x"
        double df2dy = 2; //defining partial derivative of funcion "F2(x)" wrt "y"
        
        //This part of the loop is where the Newton method is applied. 
        //It calculates the Jacobian matrix determinant, checks for division by zero, and then updates 
        //the variables (x and y) based on the Newton method's formula. 
        //The loop iterates until convergence is achieved or the maximum number of iterations is reached
        // Check for division by zero error "safety check" to check for infinity situation not created in code
        
        double det = df1dx * df2dy - df1dy * df2dx;// defining and finding Jacobian matrix determinant
        
        // Check for division by zero error "safety check" to check for infinity situation not created in code
        if (fabs(det) < 1e-10) 
        {
            cerr << "Error: Division by zero." << endl;
            return 1;
        }

        // Calculate the change in variables
        double deltaX = (f1 * df2dy - f2 * df1dy) / det;
        double deltaY = (f2 * df1dx - f1 * df2dx) / det;

        // Update variables
        x -= deltaX;
        y -= deltaY;

        // Calculate the Euclidean norm
        double norm = sqrt(deltaX * deltaX + deltaY * deltaY);

        // Print current solution and norm
        cout << "   " << i + 1 << "     " << x << "     " << y << "     " << norm << endl;

        // Check for convergence (convergence vs Iteration graph & code made in Matlab)
        if (norm < 1e-8) 
        {
            cout << "Converged to a solution." << endl;
            break;
        }
    }
    //Generated norm value arrays to futhur calculate the covergance order  
    double Norm[] = {92.7871, 46.3887, 23.1847, 11.573, 5.74799, 2.79877, 1.26189, 0.432275, 0.0662836, 0.00163537, 9.96706e-7};

    double convergenceOrders[10];
    //Convergance order loop just like in notes I have calculated P1,p2,p3 till P9 convergence convergenceOrders
    for (int i = 0; i < 9; ++i) 
    {
        convergenceOrders[i] = log(Norm[i] / Norm[i + 1]) / log(Norm[i + 1] / Norm[i + 2]);
    }

    // Calculate the average convergence order
    double averageConvergenceOrder = 0.0;
    for (int i = 0; i < 9; ++i) 
    {
        averageConvergenceOrder += convergenceOrders[i];
    }
    averageConvergenceOrder /= 9;

    // Round to the nearest 0.5 precision
    double roundedConvergenceOrder = round(averageConvergenceOrder * 2) / 2;

    cout << "Average Convergence Order: " << averageConvergenceOrder << endl;
    cout << "Rounded Convergence Order (0.5 precision): " << roundedConvergenceOrder << endl;

    return 0;

}

