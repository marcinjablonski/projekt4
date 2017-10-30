#ifndef _AnalizatorSygnalu_h_
#define _AnalizatorSygnalu_h_
#include "Sygnal.h"

using namespace std;

class AnalizatorSygnalu;
{
public:
    AnalizatorSygnalu(){}
    double dlugosc(const Sygnal& _sygnal)
    {
        double _min = _sygnal.probki[0].x;
        double _max = _sygnal.probki[0].x;
        for (int i=0; i<sygnal.probki.size(); i++)
        {
            if (_sygnal.probki[i].x < _min)
                _min = _sygnal.probki[i].x;
            if (_sygnal.probki[i].x > _max)
                _max = _sygnal.probki[i].x;
        }
        return _max - _min;
    }
    double minimum(const Sygnal& _sygnal)
    {
        double _min = _sygnal.probki[0].x;
        for (int i=0; i<sygnal.probki.size(); i++)
        {
            if (sygnal.probki[i].x < _min)
                _min = _sygnal.probki[i].x;
        }
        return _min;
    }
    double maksimum(const Sygnal& _sygnal)
	{
		double _max = _sygnal.probki[0].x;
		for ( int i=0; i<_sygnal.probki.size(); i++) {
			if (_sygnal.probki[i].x > _max)
				_max = _sygnal.probki[i].x;
		}
		return _max;
	}
	double srednia(const Sygnal& _sygnal)
	{
		double m = 0.0;
		for (int i = 0; i < _sygnal.probki.size(); ++i) {
			m += _sygnal.probki[i].x;
		}
		if (_sygnal.probki.size() > 0) {
			m /= _sygnal.probki.size();
		}
		return m;
	}

	double calka(const Sygnal& _sygnal)
	{
		double calka = 0, dt = 0, dpole = 0;
	    for (int i=0; i < _sygnal.probki.size(); i++)
	    {
	        dt = _sygnal.probki[i+1].t - _sygnal.probki[i].t;
	        dpole = (_sygnal.probki[i].x + _sygnal.probki[i+1].x) * dt / 2;
	        calka = calka + dpole;
	    }
	    return calka;
	}
};
#endif
