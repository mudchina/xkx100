// Room: /d/luoyang/luopu.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "洛浦秋风");
	set("long",  @LONG
洛河，桃李夹岸，杨柳成荫，长桥卧波，一年四季风景如画。尤在
是“金风消夏”“半月横秋”时节，更具诗情画意。三国时，曹子建说
他在河畔遇到一位神女，他就借题发挥写了一篇《洛神赋》。号称“初
唐四杰”的王勃、杨炯、卢照邻、骆宾王曾徘徊洛滨，不忍离去。唐高
宗时，上官仪循着河堤，缓辔咏诗，洛宾景色之佳，可以想见。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west"      : __DIR__"southgate",
		"southeast" : __DIR__"dukou1",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -490);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
