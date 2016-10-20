#include <iostream>
#include <cmath>
#include "solarsystem.h"
#include "euler.h"
#include "verlet.h"
#include <string>

using namespace std;

SolarSystem *solarSystem;

void sunEarth() {
    solarSystem = new SolarSystem();
    solarSystem->createCelestialBody( vec3(0,0,0), vec3(0,0,0), 1.0, 0.2, "sun", 1);
    solarSystem->createCelestialBody( vec3(1, 0, 0), vec3(0, 2*M_PI, 0), 3e-6, 0.1, "earth",4);

    vector<CelestialBody> &bodies = solarSystem->bodies();

    for(int i = 0; i<bodies.size(); i++) {
        CelestialBody &body = bodies[i]; // Reference to this body
        cout << "The position of the object is " << body.position << " with velocity " << body.velocity << endl;

    }
}

void sunEarthJupiter() {
    solarSystem = new SolarSystem();
    solarSystem->createCelestialBody( vec3(0,0,0), vec3(0,0,0), 1.0, 0.4, "sun", 1);
    solarSystem->createCelestialBody( vec3(1, 0, 0), vec3(0, 2*M_PI, 0), 3e-6, 0.1, "earth",4);
    solarSystem->createCelestialBody(vec3(5.2,0,0), vec3(0,2.59156,0),71492/149597871.0, 0.3, "jupiter",7);

    vector<CelestialBody> &bodies = solarSystem->bodies();

    for(int i = 0; i<bodies.size(); i++) {
        CelestialBody &body = bodies[i]; // Reference to this body
        cout << "The position of the object is " << body.position << " with velocity " << body.velocity << endl;

    }
}

void sunMercuryWithGR() {
    solarSystem = new SolarSystem();
    solarSystem->createCelestialBody( vec3(0,0,0), vec3(0,-12.44*2440.0/149597871.0,0), 1.0, 0.4, "sun", 1);
    solarSystem->createCelestialBody(vec3(0.3075,0,0), vec3(0,12.44,0),2440.0/149597871.0,0.05,"mercury",2);
    solarSystem->setGeneralRelativity();

    vector<CelestialBody> &bodies = solarSystem->bodies();

    for(int i = 0; i<bodies.size(); i++) {
        CelestialBody &body = bodies[i]; // Reference to this body
        cout << "The position of the object is " << body.position << " with velocity " << body.velocity << endl;

    }
}

void sunMercuryWithoutGR() {
    solarSystem = new SolarSystem();
    solarSystem->createCelestialBody( vec3(0,0,0), vec3(0,-12.44*2440.0/149597871.0,0), 1.0, 0.4, "sun", 1);
    solarSystem->createCelestialBody(vec3(0.3075,0,0), vec3(0,12.44,0),2440.0/149597871.0,0.05,"mercury",2);

    vector<CelestialBody> &bodies = solarSystem->bodies();

    for(int i = 0; i<bodies.size(); i++) {
        CelestialBody &body = bodies[i]; // Reference to this body
        cout << "The position of the object is " << body.position << " with velocity " << body.velocity << endl;

    }
}

void officialPlanetsRealistic() {
    solarSystem = new SolarSystem();
    solarSystem->createCelestialBody( vec3(3.583187837707098e-03,3.347917208376574e-03,-1.601566243263295e-04), vec3((-1.916797473876860e-06)*365.242199,(6.860577040555349e-06)*365.242199,(3.852105421771686e-08)*365.242199), 1.0,(6.955e+5)/149597871.0, "sun", 1);

    solarSystem->createCelestialBody(vec3(-1.689638050644479e-01,2.746185253985868e-01,3.783565039667143e-02), vec3((-2.941090431599825e-02)*365.242199,(-1.400673667979914e-02)*365.242199,(1.552995718374029e-03)*365.242199),2440.0/149597871.0,(2.4e+24)/(2e+30),"mercury",2);

    solarSystem->createCelestialBody(vec3(2.261833743605355e-02,-7.233613245242075e-01,-1.122302675795243e-02), vec3((2.008241010304477e-02)*365.242199,(4.625021426170730e-04)*365.242199,(-1.152705875157388e-03)*365.242199),6051.893/149597871.0, (4.9e+24)/(2e+30), "venus",3);

    solarSystem->createCelestialBody( vec3(9.779167444303752e-01,2.272281606873612e-01, -1.762900112459768e-04), vec3((-4.140900006551348e-03)*365.242199, (1.671297229409165e-02)*365.242199, (-6.071663121998971e-07)*365.242199),6378.14/149597871.0, 3e-6, "earth",4);
    //solarSystem->createCelestialBody(vec3(9.768830994836281e-01,2.247385341736485e-01,6.846869954431025e-05), vec3((-3.620432466255178e-03)*365.242199,(1.650856576752649e-02)*365.242199,(2.498599237760420e-06)*365.242199),1737.4/149597871.0, (7.349e+22)/(2e+30), "earth moon",5);

    solarSystem->createCelestialBody(vec3(1.083484179334264,-8.630838246913118e-01,-4.481984242527660e-02), vec3((9.286451652444910e-03)*365.242199,(1.212119447482730e-02)*365.242199,(2.594581334177116e-05)*365.242199),3394.0/149597871.0, (6.6e+23)/(2e+30), "mars",6);

    solarSystem->createCelestialBody(vec3(-5.433021216987578,-3.890762583943597e-01,1.231202671627251e-01), vec3((4.512629769156300e-04)*365.242199,(-7.169976033688688e-03)*365.242199,(1.969934735867556e-05)*365.242199),71492/149597871.0, (1.9e+27)/(2e+30), "jupiter",7);
    //solarSystem->createCelestialBody(vec3(-5.435359167422963,-3.929370969992803e-01,1.229116134600613e-01), vec3((7.219155786268613e-03)*365.242199,(-1.120499626271342e-02)*365.242199,(-4.325433807728170e-05)*365.242199),1565/149597871.0, (4.797e+22)/(2e+30),"europa",8);
    //solarSystem->createCelestialBody(vec3(-5.437582383804251,-3.835488841026408e-01,1.232690992424197e-01), vec3((-4.384886204372093e-03)*365.242199,(-1.115842028579346e-02)*365.242199,(-1.947231729341581e-04)*365.242199),2634/149597871.0, (1.4819e+23)/(2e+30), "ganymede",9);
    //solarSystem->createCelestialBody(vec3(-5.422030582141167,-3.831301923144091e-01,1.234560941168390e-01), vec3((-1.807631422421374e-03)*365.242199,(-2.970180625090030e-03)*365.242199,(1.229105370183902e-04)*365.242199),2403/149597871.0, (1.075938e+23)/(2e+30), "callisto",10);

    solarSystem->createCelestialBody(vec3(-2.313180120049030,-9.763200920369798,2.618183143745622e-01), vec3((5.123311296208641e-03)*365.242199,(-1.303286396807794e-03)*365.242199,(-1.814530920780186e-04)*365.242199),60268/149597871.0, 5.5e+26/(2e+30), "saturn",11);
    //solarSystem->createCelestialBody(vec3(-2.318278419731084,-9.757124624116399,2.591918531324620e-01), vec3((2.614425018677918e-03)*365.242199,(-2.876495684096870e-03)*365.242199,(8.782606158128668e-04)*365.242199),2575.5/149597871.0, (1.34553e+26)/(2e+30), "titan",12);

    solarSystem->createCelestialBody(vec3(1.847687170457543e+01,7.530306462979262,-2.114037101346196e-01), vec3((-1.513092405140061e-03)*365.242199,(3.458857885545459e-03)*365.242199,(3.234920926043226e-05)*365.242199),25559/149597871.0, (8.8e+25)/(2e+30), "uranus",13);
    //solarSystem->createCelestialBody(vec3(1.847408758996619e+01,7.530992643453827,-2.108667937915298e-01), vec3((-1.073862349820461e-03)*365.242199,(3.649319876472797e-03)*365.242199,(2.081291358842309e-03)*365.242199),788.9/149597871.0, (3.527e+21)/(2e+30),"titania",14);
    //solarSystem->createCelestialBody(vec3(1.847761373181093e+01,7.530242491512796,-2.109586288910638e-01), vec3((4.026865051762613e-04)*365.242199,(2.841057280929032e-03)*365.242199,(-3.261071362506683e-03)*365.242199),235.8/149597871.0, (6.59e+19)/(2e+30), "miranda",15);
    //solarSystem->createCelestialBody(vec3(1.847527330597616e+01,7.530741787359995,-2.107792403469114e-01), vec3((-4.979355428545024e-04)*365.242199,(3.584004645768224e-03)*365.242199,(2.538922649302682e-03)*365.242199),584.7/149597871.0, (1.172e+21)/(2e+30), "umbriel",16);
    //solarSystem->createCelestialBody(vec3(1.847685117152166e+01,7.530135653259955,-2.126687078697246e-01), vec3((-4.621136477395238e-03)*365.242199,(4.133924596783954e-03)*365.242199,(-1.016432770889346e-05)*365.242199),577.9/149597871.0, (1.353e+21)/(2e+30), "ariel",17);

    solarSystem->createCelestialBody(vec3(2.825174937236003e+01,-9.949114169366872,-4.462071175746522e-01), vec3((1.021996736183022e-03)*365.242199,(2.979258351346539e-03)*365.242199,(-8.531373744879276e-05)*365.242199),24766/149597871.0, (1.03e+26)/(2e+30), "neptune",18);
    //solarSystem->createCelestialBody(vec3(2.824985030033664e+01,-9.950522620784430,-4.460243233315587e-01), vec3((4.026865051762613e-04)*365.242199,(2.841057280929032e-03)*365.242199,(-3.261071362506683e-03)*365.242199),1352.6/149597871.0, (2.147e+22)/(2e+30), "triton",19);

    vector<CelestialBody> &bodies = solarSystem->bodies();

    for(int i = 0; i<bodies.size(); i++) {
        CelestialBody &body = bodies[i]; // Reference to this body
        cout << "The position of the object is " << body.position << " with velocity " << body.velocity << endl;

    }
}

void officialPlanetsStylized() {
    solarSystem = new SolarSystem();
    solarSystem->createCelestialBody( vec3(3.583187837707098e-03,3.347917208376574e-03,-1.601566243263295e-04), vec3((-1.916797473876860e-06)*365.242199,(6.860577040555349e-06)*365.242199,(3.852105421771686e-08)*365.242199), 1.0,(6.955e+5)/149597871.0, "sun", 1);

    solarSystem->createCelestialBody(vec3(-1.689638050644479e-01,2.746185253985868e-01,3.783565039667143e-02), vec3((-2.941090431599825e-02)*365.242199,(-1.400673667979914e-02)*365.242199,(1.552995718374029e-03)*365.242199),2440.0/149597871.0,(2.4e+24)/(2e+30),"mercury",2);

    solarSystem->createCelestialBody(vec3(2.261833743605355e-02,-7.233613245242075e-01,-1.122302675795243e-02), vec3((2.008241010304477e-02)*365.242199,(4.625021426170730e-04)*365.242199,(-1.152705875157388e-03)*365.242199),6051.893/149597871.0, (4.9e+24)/(2e+30), "venus",3);

    solarSystem->createCelestialBody( vec3(9.779167444303752e-01,2.272281606873612e-01, -1.762900112459768e-04), vec3((-4.140900006551348e-03)*365.242199, (1.671297229409165e-02)*365.242199, (-6.071663121998971e-07)*365.242199),6378.14/149597871.0, 3e-6, "earth",4);

    solarSystem->createCelestialBody(vec3(1.083484179334264,-8.630838246913118e-01,-4.481984242527660e-02), vec3((9.286451652444910e-03)*365.242199,(1.212119447482730e-02)*365.242199,(2.594581334177116e-05)*365.242199),3394.0/149597871.0, (6.6e+23)/(2e+30), "mars",6);

    solarSystem->createCelestialBody(vec3(-5.433021216987578,-3.890762583943597e-01,1.231202671627251e-01), vec3((4.512629769156300e-04)*365.242199,(-7.169976033688688e-03)*365.242199,(1.969934735867556e-05)*365.242199),71492/149597871.0, (1.9e+27)/(2e+30), "jupiter",7);

    solarSystem->createCelestialBody(vec3(-2.313180120049030,-9.763200920369798,2.618183143745622e-01), vec3((5.123311296208641e-03)*365.242199,(-1.303286396807794e-03)*365.242199,(-1.814530920780186e-04)*365.242199),60268/149597871.0, 5.5e+26/(2e+30), "saturn",11);

    solarSystem->createCelestialBody(vec3(1.847687170457543e+01,7.530306462979262,-2.114037101346196e-01), vec3((-1.513092405140061e-03)*365.242199,(3.458857885545459e-03)*365.242199,(3.234920926043226e-05)*365.242199),25559/149597871.0, (8.8e+25)/(2e+30), "uranus",13);

    solarSystem->createCelestialBody(vec3(2.825174937236003e+01,-9.949114169366872,-4.462071175746522e-01), vec3((1.021996736183022e-03)*365.242199,(2.979258351346539e-03)*365.242199,(-8.531373744879276e-05)*365.242199),24766/149597871.0, (1.03e+26)/(2e+30), "neptune",18);

    vector<CelestialBody> &bodies = solarSystem->bodies();

    for(int i = 0; i<bodies.size(); i++) {
        CelestialBody &body = bodies[i]; // Reference to this body
        cout << "The position of the object is " << body.position << " with velocity " << body.velocity << endl;

    }

}

void sunJupiterCrash(){
    solarSystem = new SolarSystem();
    //Checking if collision algorithm works
    solarSystem->createCelestialBody( vec3(0,0,0), vec3(0,0,0), 1.0,0.2, "sun crash test", 1);
    solarSystem->createCelestialBody(vec3(5,0,0), vec3(-1,0,0),71492/149597871.0, 0.1, "crashing jupiter",25);

    vector<CelestialBody> &bodies = solarSystem->bodies();

    for(int i = 0; i<bodies.size(); i++) {
        CelestialBody &body = bodies[i]; // Reference to this body
        cout << "The position of the object is " << body.position << " with velocity " << body.velocity << endl;

    }
}
/*
void runEuler() {
    int numTimesteps = 630000; //One year = 2*M_PI*(1/dt)  ===>  One Century = 630000 = numTimesteps
    double dt = 0.001;
    Euler integrator(dt);
    for(int timestep=0; timestep<numTimesteps; timestep++) {
        integrator.integrateOneStep(*solarSystem);
        solarSystem->writeToFile("positions.xyz");
    }
}
*/
void runVerlet() {
    int numTimesteps = 630000; //One year = 2*M_PI*(1/dt)  ===>  One Century = 630000 = numTimesteps
    double dt = 0.001; bool writeLogarithm = false; bool findD = true;
    string body1 = "sun"; string body2 = "mercury";
    Verlet integrator(dt);
    for(int timestep=0; timestep<numTimesteps; timestep++) {
        integrator.integrateOneStep(*solarSystem);
        if(findD) {
            solarSystem->findMaxMinDistance(body1, body1);
            if(timestep == (int)numTimesteps*0.90) {
                solarSystem->findCoordinates(body1, body2, 0.3075);
            }
        }
        if(writeLogarithm) {
           solarSystem->writeToFileLogarithm("positions.xyz");
        } else {
            solarSystem->writeToFile("positions.xyz");
        }
    }
    double years = (numTimesteps*dt)/(2*M_PI);

    cout << "The solar system is simulating "<< years << " years with " << solarSystem->bodies().size() << " objects." << endl;

    if(solarSystem->maxDistance() != 0.0) {
        cout << "Maximum distance between " << body1 << " and " << body2 << " is " << solarSystem->maxDistance() << endl;
        cout << "Minimum distance between " << body1 << " and " << body2 << " is " << solarSystem->minDistance() << endl;
    }
}

int main(){

    //Setting the output to be in logarithmic scale.
    //solarSystem->setLogarithmScale();

    //Setting center of mass.


    vec3 CM; vec3 periCoordGR; vec3 periCoordNoGR;

    //officialPlanetsRealistic();
    //sunEarthJupiter();
    sunMercuryWithGR();

    //solarSystem->setCenterOfMass(); //setting origo to be center of mass
    //solarSystem->findCenterOfMass();
    //CM = solarSystem->getCenterOfMass();

    //cout << CM << endl;
    runVerlet();
    periCoordGR = solarSystem->getPerihelionCoordinates();
    cout << "The coordinates are: " << periCoordGR << " and the theta is: " << tan(periCoordGR.y()/periCoordGR.x())*3600 << endl;
    //solarSystem->findCenterOfMass();
    //CM = solarSystem->getCenterOfMass();
    //cout << CM << endl;



    //officialPlanetsRealistic();
    //sunEarthJupiter();
    sunMercuryWithoutGR();

    //solarSystem->setMomentum();
    //solarSystem->setCenterOfMass();
    solarSystem->findCenterOfMass();
    //CM = solarSystem->getCenterOfMass();

    //cout << CM << endl;
    runVerlet();
    periCoordNoGR = solarSystem->getPerihelionCoordinates();
    cout << "The coordinates are: " << periCoordNoGR << " and the theta is: " << tan(periCoordNoGR.y()/periCoordNoGR.x())*3600 << endl;
    //solarSystem->findCenterOfMass();
    //CM = solarSystem->getCenterOfMass();
    //cout << CM << endl;


    return 0;
}

