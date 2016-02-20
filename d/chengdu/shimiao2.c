// Room: /d/chengdu/shimiao2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "大雄宝殿");
	set("long", @LONG
这里雄伟庄严的大雄宝殿，两边是青面撩牙的四大金刚，中间供奉
着如来佛祖的金像，殿内香烟缭绕，无数善男信女来此烧香磕头，正中
是一块蒲团，供香客礼拜。右手是善缘箱，供钱财布施用。
LONG	);
	set("exits", ([
		"south" : __DIR__"shimiao",
	]));
	set("objects", ([
		__DIR__"npc/yuanseng" : 1,
		__DIR__"obj/box1" : 1,
	]));
	set("coor/x", -8030);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

