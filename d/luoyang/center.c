//  Room:  /d/luoyang/center.c

inherit  ROOM;

void  create  ()
{
	set("short",  "鼓楼");
	set("long",  @LONG
一座跨街大青砖砌的拱洞高台谯楼，矗立在城中心。鼓楼为二层木
瓦建筑，设有大鼓大钟，晨钟暮鼓，用以报时。铸铁大钟高五尺，径亦
近半丈，上铸八卦和龙凤梅菊等图案。 
    鼓楼下来来往往的都是做生意的过客和游客，无论是来此购买唐三
彩还是欣赏洛阳牡丹的，都不会忘记去城郊的白马寺和龙门石窟看看。
    路旁边不显眼的地方立着一块石碑(bei)，看起来有些年代了。
LONG);
	set("item_desc",  ([
		"bei" : "
    洛阳：西周时建城，秦置洛阳县。东周、东汉、三国
魏、西晋、北魏、隋(炀帝)、唐(武后)、后梁、后唐等九
朝故都，是为文化名城，七大古都之一。
\n",
	]));
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"  :  __DIR__"eastroad",
		"west"  :  __DIR__"westroad",
		"south" :  __DIR__"southroad",
		"north" :  __DIR__"northroad",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -500);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
