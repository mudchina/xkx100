// Room: /d/yueyang/longsheshan.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "龙舌山");
	set("long", @LONG
君山地形酷似乌龙卧水，龙涎井前方为龙口，张口向南，两边钳形
山嘴，岩壁拱护，为龙的上、下腭，中间的小山为龙舌头，山势平舒，
形态逼真，此山因此得名。当年湘妃寻夫至君山，口渴异常。她们的忠
贞感动了洞庭湖中的乌龙。乌龙化着一座小山，张开双腭，伸出舌头，
让龙涎滴出，滴在山角下，化成一口古井。湘妃见到古井，饱喝了一顿
井中仙甜的龙涎。顿觉精神振着。湘妃投湖后，乌龙悲伤过度，化为一
座小山，便是这座龙舌山。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"northdown" : __DIR__"liuyijing",
		"southdown" : __DIR__"feilaizhong",
	]));
	set("objects", ([
		__DIR__"npc/xiaofan" : 1,
	]));
	set("coor/x", -1720);
	set("coor/y", 2320);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
