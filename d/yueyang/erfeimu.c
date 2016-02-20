// Room: /d/yueyang/erfeimu.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "二妃墓");
	set("long", @LONG
二妃墓在君山岛的东麓，与岳阳古城隔湖相望。墓两边的石刻对联
是：“君妃二魄芳千古，山竹诸斑泪一人。”这“泪一人”典出：虞舜
南巡，崩于苍梧，他的两个爱妃娥皇和女寻夫来到洞府山，忽闻噩耗，
悲痛万分，遂攀竹痛哭，泪血滴在竹子上，竟成斑竹。二妃因悲恸而死
于君山并葬此。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"banzhu2",
		"west"      : __DIR__"banzhu3",
		"south"     : __DIR__"banzhu1",
		"northup"   : __DIR__"shanliang",
		"southwest" : __DIR__"shijie2",
		"northeast" : __DIR__"xiaolu6",
	]));
	set("coor/x", -1670);
	set("coor/y", 2300);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
