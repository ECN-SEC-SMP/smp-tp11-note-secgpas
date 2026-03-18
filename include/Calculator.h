#pragma once
class Calculator
{
public:
	/// <summary>
	/// Calcul le produit des nombres entiers strictement positifs infrieurs ou gaux  l'entier a
	/// </summary>
	/// <param name="a"></param>
	/// <returns></returns>
	int factorielle(int a);

	/// <summary>
	/// Calcul la somme des entiers a et b
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	int add(int a, int b);

	/// <summary>
	/// Calcul la soustraction entre les entiers a et b
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	int sub(int a, int b);

	/// <summary>
	/// Calcul la division de a par b
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	double div(double a, double b);
};