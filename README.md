# Multiplication of Large Integers Using Karatsuba's Algorithm
[![Build Status](https://travis-ci.com/ezquire/Karatsuba.svg?branch=master)](https://travis-ci.com/ezquire/Karatsuba)

Two applications of Karatsuba's algorithm. The first multiplies two large integers and the second involves exponentiation.


Group
-----

Tyler Gearing, Mei Williams


Usage
-----

To build executable run
```
make
```

Then you can the program from the current directory by typing
```
./suba
```

To clear the output files and executables use
```
make clean
```

Sample Output
-----

```
./suba

Enter 1, 2, or 3
1) Multiplication
2) Exponentiation
3) Quit
1

Input an integer less than or equal to 1000 for A: 999 
Input an integer less than or equal to 1000 for B: 999

Performing multiplication with input: 999, 999
999x999 = 998001

Enter 1, 2, or 3
1) Multiplication
2) Exponentiation
3) Quit
2

Input an integer less than or equal to 1000 for A: 999
Input an integer less than or equal to 1000 for B: 999

Performing exponentiation with input: 999, 999
999^999 = 368063488259223267894700840060521865838338232037353204655959621437025609300472231530103873614505175218691345257589896391130393189447969771645832382192366076536631132001776175977932178658703660778465765811830827876982014124022948671975678131724958064427949902810498973271030787716781467419524180040734398996952930832508934116945966120176735120823151959779536852290090377452502236990839453416790640456116471139751546750048602189291028640970574762600185950226138244530187489211615864021135312077912018844630780307462205252807737757672094320692373101032517459518497524015120165166724189816766397247824175394802028228160027100623998873667435799073054618906855460488351426611310634023489044291860510352301912426608488807462312126590206830413782664554260411266378866626653755763627796569082931785645600816236891168141774993267488171702172191072731069216881668294625679492696148976999868715671440874206427212056717373099639711168901197440416590226524192782842896415414611688187391232048327738965820265934093108172054875188246591760877131657895633586576611857277011782497943522945011248430439201297015119468730712364007639373910811953430309476832453230123996750235710787086641070310288725389595138936784715274150426495416196669832679980253436807864187160054589045664027158817958549374490512399055448819148487049363674611664609890030088549591992466360050042566270348330911795487647045949301286614658650071299695652245266080672989921799342509291635330827874264789587306974472327718704306352445925996155619153783913237212716010410294999877569745287353422903443387562746452522860420416689019732913798073773281533570910205207767157128174184873357050830752777900041943256738499067821488421053870869022738698816059810579221002560882999884763252161747566893835178558961142349304466506402373556318707175710866983035313122068321102457824112014969387225476259342872866363550383840720010832906695360553556647545295849966279980830561242960013654529514995113584909050813015198928283202189194615501403435553060147713139766323195743324848047347575473228198492343231496580885057330510949058490527738662697480293583612233134502078182014347192522391449087738579081585795613547198599661273567662441490401862839817822686573112998663038868314974259766039340894024308383451039874674061160538242392803580758232755749310843694194787991556647907091849600704712003371103926967137408125713631396699343733288014254084819379380555174777020843568689927348949484201042595271932630685747613835385434424807024615161848223715989797178155169951121052285149157137697718850449708843330475301440373094611119631361702936342263219382793996895988331701890693689862459020775599439506870005130750427949747071390095256759203426671803377068109744629909769176319526837824364926844730545524646494321826241925107158040561607706364484910978348669388142016838792902926158979355432483611517588605967745393958061959024834251565197963477521095821435651996730128376734574843289089682710350244222290017891280419782767803785277960834729869249991658417000499998999
```