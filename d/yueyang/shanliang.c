// Room: /d/yueyang/shanliang.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "小山梁");
	set("long", @LONG
你站在一座小山梁上，远处波帆点点，银粼闪烁，晚归晨起的渔歌
声声萦耳。近处，碧玉青螺般的君山如青龙横卧万顷洞庭湖波中，鸡鸣
炊烟四起，一派世外桃源风光。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"northdown" : __DIR__"xiaolu4",
		"southdown" : __DIR__"erfeimu",
	]));
	set("coor/x", -1670);
	set("coor/y", 2310);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
