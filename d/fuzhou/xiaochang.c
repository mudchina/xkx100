// Room: /d/fuzhou/xiaochang.c
// Date: may.12 1998 Java
inherit ROOM;

void create()
{
	set("short", "校场");
	set("long", @LONG
福州校场为福建水师校场。场中点将楼上高挂“施”字黑锈金边帅
旗，刀枪耀日生辉。水师提督施琅施大人亲率十万雄兵，隔海相望，壮
心不已。
LONG );
	set("exits", ([ /* sizeof() == 1 */
	    "west"   : __DIR__"nanmendou",
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1850);
	set("coor/y", -6320);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
