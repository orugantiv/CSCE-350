#include <Project_1/inc/Oruganti_V.N.Anirudh_NumberGenrator.h>

NumberGenrator::NumberGenrator(std::vector<float>::size_type numberLenth){
    std::random_device random_device;
    std::default_random_engine eng(random_device());
    std::uniform_real_distribution<float> genrator(LEFT_BOUND, RIGHT_BOUND);
    
    for(std::vector<float>::size_type i = 0; i<numberLenth;++i)
        _genratedValues.push_back((genrator(eng)));
}
std::vector<float> NumberGenrator::getGenratedValues(){
    return _genratedValues;
}
void NumberGenrator::clearValues(){
    _genratedValues.clear();
}