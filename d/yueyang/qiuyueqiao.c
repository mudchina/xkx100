// Room: /d/yueyang/qiuyueqiao.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "秋月桥");
	set("long", @LONG
位于湘妃祠引道左侧，为半园石拱桥，桥下为一片荷塘。拱桥的半
园拱倒映在荷塘中恰似一轮跳动的秋月。传说站在秋月桥上观秋月倒映
在秋月井中，能看见嫦娥抱着玉兔守着广寒宫的寂寞情景，只可惜这口
井早已不复存在了。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"south"     : __DIR__"xiaolu7",
		"northup"   : __DIR__"qiuyueting",
	]));
	set("coor/x", -1670);
	set("coor/y", 2330);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
