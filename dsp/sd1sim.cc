// generated from file './/sd1sim.dsp' by dsp2cc:
// Code generated with Faust 0.9.73 (http://faust.grame.fr)

namespace sd1sim {

template <int tab_size>
struct table1d_imp {
    float low;
    float high;
    float istep;
    int size;
    float data[tab_size];
};

static table1d_imp<100> sd1table __rt_data = {
	0,0.970874,101.97,100, {
	0.0,-0.0296601120503,-0.0598674248409,-0.0905150007138,-0.121308375456,
	-0.151467182949,-0.179391228543,-0.20311322845,-0.22181217708,-0.236184615832,
	-0.247393860941,-0.256392748011,-0.263832596851,-0.27014260674,-0.275608935192,
	-0.280427503638,-0.284736454202,-0.288635961456,-0.292200539725,-0.295486884764,
	-0.298539006357,-0.301391676307,-0.304072801593,-0.306605094452,-0.309007271702,
	-0.311294931935,-0.313481207932,-0.315577259282,-0.317592649535,-0.319535638647,
	-0.321413412363,-0.323232264095,-0.324997740556,-0.326714759449,-0.328387705392,
	-0.330020508732,-0.331616710793,-0.333179518278,-0.334711848943,-0.336216370187,
	-0.337695531875,-0.339151594422,-0.340586652974,-0.342002658352,-0.343401435316,
	-0.34478469858,-0.346154066961,-0.347511075957,-0.348857189018,-0.350193807722,
	-0.35152228104,-0.352843913855,-0.354159974866,-0.355471704003,-0.356780319459,
	-0.358087024452,-0.359393013789,-0.360699480344,-0.362007621514,-0.363318645771,
	-0.364633779358,-0.365954273265,-0.367281410556,-0.368616514174,-0.369960955336,
	-0.371316162672,-0.372683632257,-0.374064938737,-0.37546174776,-0.376875829991,
	-0.378309077013,-0.379763519526,-0.381241348294,-0.382744938433,-0.384276877772,
	-0.385840000186,-0.387437425041,-0.389072604227,-0.390749378636,-0.392472046537,
	-0.394245447015,-0.396075062727,-0.397967147639,-0.399928887472,-0.401968603505,
	-0.404096014656,-0.406322579135,-0.408661946583,-0.411130566638,-0.413748523791,
	-0.416540707759,-0.419538495504,-0.422782239351,-0.426325074517,-0.430238986457,
	-0.434624967197,-0.439631090453,-0.445487308035,-0.452579839466,-0.461635627071
	}
};

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT	*fslider0_;
	double 	fRec0[2];
	int 	iConst0;
	double 	fConst1;
	double 	fConst2;
	double 	fConst3;
	double 	fConst4;
	double 	fRec2[2];
	double 	fConst5;
	double 	fConst6;
	double 	fVec0[2];
	double 	fConst7;
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT	*fslider1_;
	double 	fRec4[2];
	double 	fConst8;
	double 	fConst9;
	double 	fConst10;
	double 	fConst11;
	double 	fConst12;
	double 	fRec3[2];
	double 	fVec1[2];
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT	*fslider2_;
	double 	fConst13;
	double 	fRec1[2];
	void connect(uint32_t port,void* data);
	void clear_state_f();
	void init(uint32_t samplingFreq);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);

	static void clear_state_f_static(PluginLV2*);
	static void init_static(uint32_t samplingFreq, PluginLV2*);
	static double sd1nonlin(double x);
	static void compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2*);
	static void del_instance(PluginLV2 *p);
	static void connect_static(uint32_t port,void* data, PluginLV2 *p);
public:
	Dsp();
	~Dsp();
};



Dsp::Dsp()
	: PluginLV2() {
	version = PLUGINLV2_VERSION;
	id = "sd1sim";
	name = N_("Super Overdrive");
	mono_audio = compute_static;
	stereo_audio = 0;
	set_samplerate = init_static;
	activate_plugin = 0;
	connect_ports = connect_static;
	clear_state = clear_state_f_static;
	delete_instance = del_instance;
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int i=0; i<2; i++) fRec0[i] = 0;
	for (int i=0; i<2; i++) fRec2[i] = 0;
	for (int i=0; i<2; i++) fVec0[i] = 0;
	for (int i=0; i<2; i++) fRec4[i] = 0;
	for (int i=0; i<2; i++) fRec3[i] = 0;
	for (int i=0; i<2; i++) fVec1[i] = 0;
	for (int i=0; i<2; i++) fRec1[i] = 0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	iConst0 = min(192000, max(1, fSamplingFreq));
	fConst1 = double(iConst0);
	fConst2 = (2.08234114092347e-05 * fConst1);
	fConst3 = (0.000476252356733052 + fConst2);
	fConst4 = ((0.000476252356733052 - fConst2) / fConst3);
	fConst5 = (2.02358669144664e-05 * fConst1);
	fConst6 = (0 - fConst5);
	fConst7 = (1.0 / fConst3);
	fConst8 = (9.4e-08 * iConst0);
	fConst9 = (0.00044179999999999995 * iConst0);
	fConst10 = (1 + fConst9);
	fConst11 = (1.0 / (fConst10 * fConst3));
	fConst12 = (0 - ((1 - fConst9) / fConst10));
	fConst13 = (3.141592653589793 / double(iConst0));
	clear_state_f();
}

void Dsp::init_static(uint32_t samplingFreq, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

double always_inline Dsp::sd1nonlin(double x) {
    double f = fabs(x);
    f = (f/(3.0 + f) - sd1table.low) * sd1table.istep;
    int i = static_cast<int>(f);
    if (i < 0) {
        f = sd1table.data[0];
    } else if (i >= sd1table.size-1) {
        f = sd1table.data[sd1table.size-1];
    } else {
	f -= i;
	f = sd1table.data[i]*(1-f) + sd1table.data[i+1]*f;
    }
    return copysign(f, -x);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fslider0 (*fslider0_)
#define fslider1 (*fslider1_)
#define fslider2 (*fslider2_)
	double 	fSlow0 = (0.0010000000000000009 * pow(10,(0.05 * double(fslider0))));
	double 	fSlow1 = (4.748558434412966e-05 * (exp((5 * double(fslider1))) - 1));
	double 	fSlow2 = (1.0 / tan((fConst13 * double(fslider2))));
	double 	fSlow3 = (1 + fSlow2);
	double 	fSlow4 = (1.0 / fSlow3);
	double 	fSlow5 = (0 - ((1 - fSlow2) / fSlow3));
	for (int i=0; i<count; i++) {
		fRec0[0] = ((0.999 * fRec0[1]) + fSlow0);
		fRec2[0] = ((double)input0[i] - (fConst4 * fRec2[1]));
		double fTemp0 = ((fConst6 * fRec2[1]) + (fConst5 * fRec2[0]));
		fVec0[0] = fTemp0;
		double fTemp1 = (fConst7 * fVec0[0]);
		fRec4[0] = (fSlow1 + (0.993 * fRec4[1]));
		double fTemp2 = (fConst8 * (37700 + (1000000 * fRec4[0])));
		fRec3[0] = ((fConst12 * fRec3[1]) + (fConst11 * ((fVec0[0] * (1 + fTemp2)) + (fVec0[1] * (1 - fTemp2)))));
		double fTemp3 = (fTemp1 - sd1nonlin((fRec3[0] - fTemp1)));
		fVec1[0] = fTemp3;
		fRec1[0] = ((fSlow5 * fRec1[1]) + (fSlow4 * (fVec1[0] + fVec1[1])));
		output0[i] = (FAUSTFLOAT)(fRec1[0] * fRec0[0]);
		// post processing
		fRec1[1] = fRec1[0];
		fVec1[1] = fVec1[0];
		fRec3[1] = fRec3[0];
		fRec4[1] = fRec4[0];
		fVec0[1] = fVec0[0];
		fRec2[1] = fRec2[0];
		fRec0[1] = fRec0[0];
	}
#undef fslider0
#undef fslider1
#undef fslider2
}
		
void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case DRIVE: 
		fslider1_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case LEVEL: 
		fslider0_ = (float*)data; // , -16.0, -2e+01, 4.0, 0.1 
		break;
	case TONE: 
		fslider2_ = (float*)data; // , 4e+02, 1e+02, 1e+03, 1.03 
		break;
	default:
		break;
	}
}

void Dsp::connect_static(uint32_t port,void* data, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->connect(port, data);
}


PluginLV2 *plugin() {
	return new Dsp();
}

void Dsp::del_instance(PluginLV2 *p)
{
	delete static_cast<Dsp*>(p);
}

/*
typedef enum
{
   DRIVE, 
   LEVEL, 
   TONE, 
} PortIndex;
*/

} // end namespace sd1sim
