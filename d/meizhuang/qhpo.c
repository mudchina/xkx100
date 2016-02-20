// /d/meizhuang/qhpo.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "奇槐坡");
	set("long", @LONG
这里就是奇槐坡了，这里种着大大小小，千奇百怪的槐树，有的槐
树一直向天，有的又曲折盘绕，你从这里隐隐约约听到一阵阵的琴声，
似有似无，若隐若现。
LONG
	);
	set("outdoors", "meizhuang");
	set("exits", ([ /* sizeof() == 2 */
		"eastup" : __DIR__"xiaodao",
		"north"  : __DIR__"senlin1",
	]));
	set("no_clean_up", 0);

	set("coor/x", 3500);
	set("coor/y", -1440);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
