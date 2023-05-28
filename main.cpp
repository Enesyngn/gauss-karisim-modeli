#include <iostream>
#include <cmath>

#define NUM_COMPONENTS 3

struct Gaussian {//Gaussianyapý yapýsý, her bir yapýnýn ortalama ( mean), varyans ( variance) ve aðýrlýðýný (weight ) içerir.
    double mean;
    double variance;
    double weight;
};

double gaussian_pdf(double x, double mean, double variance) {//gaussian_pdfiþlevi, belirli bir þekilde anlaþýlmasý için x gözlemcileri Gauss olasýlýklarý hakkýnda açýklamalar hesaplar.
    return (1.0 / std::sqrt(2 * M_PI * variance)) * std::exp(-std::pow(x - mean, 2) / (2 * variance));
}

double gaussian_mixture_pdf(double x, Gaussian* components, int num_components) {//gaussian_mixture_pdfiþlevi, x deðeri için Gauss karýþýmý hesaplamasýný hesaplamak için aðýrlýk aðýrlýklarýný ve özelliklerini kullanýr.
    double pdf_sum = 0.0;
    for (int i = 0; i < num_components; i++) {
        pdf_sum += components[i].weight * gaussian_pdf(x, components[i].mean, components[i].variance);//componentsvektörü oluþturur. Bir xdeðerin belirlendiði ve bu deðer için Gauss daðýlým olasýlýklarýndan yararlanýlýr ve ekrana yazdýrýlýr.
    }
    return pdf_sum;
}

int main() {
    Gaussian components[NUM_COMPONENTS] = {
        {2.0, 1.0, 0.4},
        {5.0, 0.5, 0.3},
        {8.0, 2.0, 0.3}
    };

    double x = 4.5; // Test edilecek deðer

    double pdf = gaussian_mixture_pdf(x, components, NUM_COMPONENTS);

    std::cout << "Gaussian Mixture PDF: " << pdf << std::endl;

    return 0;
}
