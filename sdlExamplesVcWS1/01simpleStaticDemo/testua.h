#ifndef TESTUA_H
#define TESTUA_H
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include "OurTypes.h"


#define AZALPENGENERALA "Kaixo, unibertsitario baten bizimoduan murgiltzeko gogoz? Puntu exe egokia ireki duzu orduan. Nola, terminologia honekin ez zaudela egokituta? Bada ba garaia, izan ere, informatikako gradua ikasten ari den mutil gazte baten lekuan jarriko zaitugu, eta ikasgai guztiak gainditzea zure esku egongo da. Badakigu honelako karrera batek eskatzen duen esfortzuari ez zaudela ohituta. Baina zu lasai, izan ere, ez dugu zuk ikasgairik aprobatzea espero. Bueno ba, zerren zain zaude? Nahi duzun lo guztia egitera ohituta? Bada zure ohiturak aldatzen hasteko garaia, jaiki, gaur ere berandu iritsiko zara bestela."
#define ESNATUONA "Zorionak, nahikoa kostatu bazaizu ere lortu duzu azkenean esnatzea. Egia esan ez nuen horren urruti iritsiko zinenik espero. Baina hau eguneko lehen oztopoa besterik ez da izan. Orain beste eginkizun gogor bat datorkizu, 11. eraikinera garaiz iristea. Izan ere, bertara iristeko bidea beste edozein baina gogorragoa da. Hobe duzu bidean ez galdu eta garaiz iritsi zure lehenengo klasera."
#define ESNATUBERANDU "Kostata baina azkenean esnatu zara. Egia esan nik uste baina gehiago iraun duzu. Baina oraindik klaseetara iristeko 11. eraikinera iritsi behar duzu. Eta ez badirudi ere hau ez da lan erraza. Hobe duzu azkar ibili, berandu iritsiko zara bestela."
#define ESNATUOSOBERANDU "Inoiz baina gehiago kostata baina zure etxeko guztiak esnatu ondoren jaiki zara. Badirudi gauetan ezingo zarela hainbeste LOL partidetara ibili. Baina gauza batzuk sakrifikatu egin behar izaten dira bizitza honetan."
#define EZESNATU "Bueno azkenean eguneroko moduan ez zara esnatu. Zer egingo diogu ba, bihar agian. Banekien ez zinela informatiko baten kontrola hartzeko prest, baina ahalegindu beharra genuen. Azken finean froga eta errore metodologia da egokiena ezta?"
#define KLASEAONDOIRITSI "Iritsi zara unibertsitatera, egia esan gure uste guztiak gainditzen hari zara. Baina zu lasai, oraindik bost klase ordu gogor geratzen zaizkizu eta."
#define KLASEABERANDU "Azkenean, gaur ere berandu iritsi zara klasera. Baina zu lasai inorrek ikusi gabe sartuaz gero ez da arazorik egongo ezta?"
#define KLASEOSOBERANDU "Zu klasera iristerako ia eguna bukatu da, baina irakasleak zerrenda pasa ez duenez..."
#define URETAERORI "ETAAAAAA... URETARA... Ikusi duzu informatikoen bizitza ez dela erraza ezta? Bueno zu lasai, bilatuko dugu eta bizitza hau zu baina hobeto egingo duen bat. Izan ere, ez da oso zaila..."
#define MATEAZALPENA "Matematikako klasera iritsi zara. Ez dago gaizki, izan ere, hasieran zure gaitasunak ikusita ez nuen uste horren urrutira iritsiko zinenik.Badakigu matematikak ez direla zure gustuko klaseak eta horregatik, batzuetan deskantsu bat hartzea gaizki ez dagoenez, ordu honetan deskantsu bat hartzeko aukera emango dizugu. Hobe duzu irakaslea begira ez dagoenean soilik ibili."
#define MATEONDO "Abilezia handiz ekidin dituzu irakaslearen begiratu guztiak. Benetako informatiko baten kualitate guztiak eskuratzen hari zara. Izan ere, ba al da pantailaz bizkor aldatzea baina kualitate hoberik?"
#define MATETARTE "Amaitu da klasea eta irakaslearen begiratu guztiak ekidin dituzun arren, ez zara zuk nahi zenuen guztia ibili jolasten."
#define MATEGAIZKI "Amaitu da klasea eta ez zara ia ezer ibili jolasean. Ematen duenez, informatiko lanngile eta arduratsu baten bizitzan murgiltzen ari zara."
#define MATEOSOGAIZKI "Jolasean ari zinela irakasleak bete betean harrapatu zaitu. Klasetik bota eta falta bat jarri dizu, baina zure deskantsu pertsonalaz ari garenean ezerk ez zaitu geratuko. Gainera honelako kastigu batek ez du zu hurrengo klasera joatea ekidingo."
#define OINARRIAZALPENA "Aurreko oztopo gogor guztiak igaro eta gero Oinarri Metodologikoen ikasgaira iritsi zara. Uste dut momentua hau gure arteko sekretu batzuk azaltzeko egokia dela. Bueno ni hasiko naiz, klase honen amaieran, duela bi aste bidalitako txostena entregatu beharra daukazu eta ez duzu dokumentua sortu ere egin. Bueno zorte on, ea klase amaierarako amaitzea lortzen duzun."
#define OINARRIONDO "Txostena garaiz entregatzea lortu duzu. Ez dut positiboegia izan nahi baina honela jarraituaz gero ikasgai bat gainditzea lortuko duzu. Segi horrela!"
#define OINARRITARTE "Zure txostena egiturari begiratuta desastre totala izan arren, estilo dezente bat mantentzeko gai izan zarenez baliteke gainditzea. Nik uste arro egoteko moduko lana dela."
#define OINARRIGAIZKI "Txostena entregatu duzu baina emaitza ikusita hobe ezer entregatu ez bazenu. Suspentso bat gehiago zakurako."
#define OINARRIOSOGAIZKI "Ez zara txostena garaiz entregatzeko gai izan, baina zu lasai, izan ere, beste 0 batek ez du zure espediente akademikoan garrantzia handirik edukiko."
#define PROGRAMAZALPENA "Programazioko klasean zaude eta beti bezala ilargian egon zara irakasleak azalpen guztiak eman dituenean. Eta hori honela ez dela eta klase osoa arretaz igaro duzula erakusteko asmoz galdera batzuk egitea erabaki duzu. Pertsonalki ez dut uste oso ideia ona denik baina ez naiz inor zure taktikak zalantzan jartzeko. Izan ere, ez dut uste nireak hobeak direnik. Bueno hobe duzu galdera hauek irakasleak azaldutako ezer ez izatea. Zorte on!"
#define PROGRAMONDO "Zorionak. Galdera egokiak egitea lortu duzu eta honi esker irakasleak bere ikasle gogotsuena zarela uste du. Ea honela azterketan laguntza apur batekin gainditzen duzun, bestela ikasgaia gainditzea zaila duzu eta."
#define PROGRAMTARTE "Galdera guztiak zuzenak izan ez badira ere ez duzu ridikulu totala egin eta hori eskertzekoa da. Ez dut uste ikasgaia gainditzeko nahikoa izango denik, baina suerte pixka batekin..."
#define PROGRAMGAIZKI "Galdera guztiak okerrak izan ez badira ere, eskertzekoa da galdera guztiak gazki egiteko egin duzun esfortzua. "
#define PROGRAMOSOGAIZKI "Zorionak. Galdera egokiak egin dituzu... mmmm egia esan ez. Baina nik ere jolasteko aukera dut ez? Zure sentimenduekin soilik bada ere. Beste batean izan beharko du. Zu segi gogor ahalegintzen."
#define REDESAZALPENA "Iritsi zara astearen erdira, badakit gogorra izan dela, baina zu lasai hau igaro ondoren etxean ordenagailua zure zain izango duzu eta. Ikasgai honetan gainera ez duzu lan gogorrik egin beharko izan ere irudian ikusiko dituzun kableak jarraituaz zein ordenagailu dauden elkarrekin konektatuta asmatu beharko duzu. Eta hau gogo apur batekin LH3-ko batek ere lortu dezake."
#define REDESONDO "Ez da oso lan gogorra izan baina ongi egin duzunez zoriondu egin beharko zaitut. ZORIONAK!"
#define REDESTARTE "Ez da desastre totala izan, baina ala ere, etzara guztiak asmatzeko gai izan."
#define REDESGAIZKI "Ez zara hain eginkizun sinplea ongi egiteko gai izan egia esan gauzak gaizki egiteko zure abilezia gutxietsi egiten nuen."
#define REDESOSOGAIZKI "Ez zara hain eginkizun sinplea ongi egiteko gai izan egia esan gauzak gaizki egiteko zure abilezia gutxietsi egiten nuen."
#define FISIKAAZALPENA "Iritsi da zure kotxe lerro jarraitzailea entregatzeko garaia. Eta atzo gauean muntatu zenuenez ez da lerro bat ongi jarraitzeko gai. Baina arrazoi hau ez da nahiko zure bosta eskuratzeko garaian eta zure mando teledirigituarekin konektatu duzu. Honek lerroa jarraitzeko aukera emango dizu baina honetarako abilezia handia beharko duzu lerrotik atera eta zure nota zero bat izango da eta."
#define FISIKAONDO "Zorionak! Kotxeak lerroa primeran jarraitu du eta proiektua gainditzea eskuratu duzu. Martxa honetan fisika gainditzea lortuko duzu. Ez dago batere gaizki!"
#define FISIKATARTE "Kotxeak ez du lerroa behar bezala jarraitu baina irakaslea nahikoa umore onez zegoenez datorren asterarte utzi dizu kotxeak arazorik gabe funtzionatu dezan. Baina biok dakigunez ez duzula lanik egingo, hobe duzu pila berriak erostera joan."
#define FISIKAGAIZKI "Kotxeak ez du lerroa behar bezala jarraitu baina irakaslea nahikoa umore onez zegoenez datorren asterarte utzi dizu kotxeak arazorik gabe funtzionatu dezan. Baina biok dakigunez ez duzula lanik egingo, hobe duzu pila berriak erostera joan."
#define FISIKAOSOGAIZKI "Zure ideia desastre bat izan da! Nola izango zenuen mando bat konektatzeko ideia. Orain zero bat edukitzeaz gain zure gelakide guztiek barre egiten dizute aurpegira. Baina informatiko baten bizitzan lagunik ez edukitzeak ez duenez gehiegi inporta ez da horrenbesteko arazoa izango. Zu lasai."
#define EGUNONA "Zorionak zure eguneko eginkizunen batezbestekoa begiratuta, emaitza oso ona izan da. Honela jarraituaz gero PoPBL-raino iritsi zintezke hori bai informatikako titulua eskuratzea ez da lan erraza izango."
#define EGUNERTAINA "Garko eguna onargarria izan da baina PoPBL-an parte hartu nahi baduzu zerbait gehiago egiten hasi beharko duzu."
#define EGUNTXARRA "Zure gaurko eguna desastre total bat izan da. Karrera gainditu nahi izanez gero hobe duzu espabilatu."
#define ASTEONA "Zure asteak nire espektatiba guztiak gainditu ditu. Agian joko txoroak alde batera utzi eta benetako karreran sartzea pentsatu beharko zenuke."
#define ASTEERTAINA "Ez dut uste inoiz informatikako titulua eskuratuko duzunik baina agian gogor ahaleginduaz gero hirugarren urterarte iritsi zintezke. "
#define ASTETXARRA "Espero nuen moduan zure astea desastre bat izan da. Baina zu lasai unibertsitateaz gain beste bide batzuk ere badaude eta agian hurrengo Steve Jobs bilakatu zintezke."


char str[50][100];
void parrafoaidatzi(int hasierax, int hasieray, int karakterlineako, char* testua,int r, int g, int b);//Testu bat nahi duzun tokian, nahi duzun kolorearekin idazte du nahi duzun luzerako lerrotan banatuta
int lerrotanbanatu(int lerroluzeramax, char* testua);//Karaktere kate luze bat kate motzagotan banatzen du 
int hitzluzera(int posizioa, char* str);// hitz batek zer luzera duen itzultzen du
#endif