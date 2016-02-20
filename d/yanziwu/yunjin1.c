// Room: /d/yanziwu/yunjin1.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "云锦一楼");
	set("long", @LONG
小楼檐下一块匾额，写着“云锦楼”三个墨绿篆字，楼下前后左右
种的都是茶花。但这些茶花在大理都不过是三四流货色，和这精致的楼
阁亭榭相比，未免不衬。
LONG );
	set("exits", ([
		"north"  : __DIR__"path8",
		"south"  : __DIR__"garden",
		"up"     : __DIR__"yunjin2",
	]));
	set("objects", ([
		"/d/dali/obj/chahua11" :1,
		__DIR__"npc/xiaocha" :1,
	]));
	set("coor/x", 1230);
	set("coor/y", -1260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}