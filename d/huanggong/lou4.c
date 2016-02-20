// Room: /d/huanggong/lou4.c

inherit ROOM;

void create()
{
	set("short", "角楼");
	set("long", @LONG
角楼中央是一个三开间的方亭楼, 四出抱厦. 最顶部十字脊镀金宝
顶以下, 计有三层檐, 九梁, 十八柱, 七十二条脊, 上下重叠, 纵横交
错. 底座是白玉石台基周围饰以白玉栏杆. 它紧扼内城一角, 能控制四
下, 内城四角各有一座这样的角楼, 若有风吹草动, 都可一清二楚.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 1 */
		"down" : __DIR__"jiao4",
	]));
	set("no_clean_up", 0);

	set("coor/x", -230);
	set("coor/y", 5240);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}