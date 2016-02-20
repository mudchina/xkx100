// Room: /d/wuxi/jinlianqiao.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "金莲桥");
	set("long", @LONG
这是一座三孔石桥，每孔六块石梁。桥台的两端是八个横帽雕有怪
鱼头和螭头各四个。华版石上刻的“童子穿牡丹”图栩栩如生。石栏杆
由莲花状望柱和透空栏板组成，还雕有荷叶净瓶和拐杖。整座桥造型优
美匀称，美仑美奂，梁溪河水从桥下潺潺流过，南北都是闹市大街，桥
上人来人往。
LONG );
	set("outdoors", "wuxi");
	set("exits", ([
		"north" : __DIR__"northroad2",
		"south" : __DIR__"northroad1",
	]));
	set("objects", ([
			"/d/city/npc/liumang" : 2,
	]));
	set("coor/x", 370);
	set("coor/y", -780);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}