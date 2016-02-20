// Room: /d/taishan/zhuoquan.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "酌泉亭");
	set("long", @LONG
云步桥东酌泉亭，又名观瀑亭。北侧有联：“且依石栏观飞瀑，再
渡云桥访爵松。”云步桥周围有“月色泉声”、“云步跻天”、“耸壑
昂霄”、“气象岩岩”等题刻五十余处，真、草、隶、篆，诸体荟萃，
琳琅满目。
LONG );
	set("exits", ([
		"west" : __DIR__"yunbu",
	]));
	set("outdoors", "taishan");
	set("resource/water", 1);
	set("no_clean_up", 0);
	set("coor/x", 400);
	set("coor/y", 680);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
