// Room: /d/changcheng/nroad2.c
// Last Modified by Winder on Aug. 25 2000

inherit ROOM;

void create()
{
	set("short", "大驿道");
	set("long", @LONG
你走在一条尘土飞扬的大驿道上。四周的人不是很多。偶尔有几个
挑夫，匆匆向南走去。不时还有两三骑快马从身边飞驰而过，扬起一路
尘埃。道路两旁是整整齐齐的杨树林。从这里远远的就可以望见南边的
北京城。
LONG );
        set("outdoors", "changcheng");
	set("exits", ([
		"south" : __DIR__"nroad1",
		"north" : __DIR__"juyongguan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -190);
	set("coor/y", 4600);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

