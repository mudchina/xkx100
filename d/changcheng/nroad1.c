// Room: /d/changcheng/nroad1.c
// Last Modified by Winder on Aug. 25 2000

inherit ROOM;

void create()
{
	set("short", "大驿道");
	set("long", @LONG
你走在一条尘土飞扬的大驿道上。四周人来人往。挑担子的、行商
的、赶着大车的马夫、大多数人都是向南去京城，熙熙攘攘，非常热闹。
不时还有两三骑快马从身边飞驰而过，扬起一路尘埃。道路两旁是整整
齐齐的杨树林。从这里远远的就可以望见北京城的北城门。
LONG );
        set("outdoors", "changcheng");
	set("exits", ([
		"south" : "/d/beijing/anding",
		"north" : __DIR__"nroad2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -190);
	set("coor/y", 4500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
