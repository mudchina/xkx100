// Room: /d/yueyang/dongtingmiao1.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "洞庭庙主殿");
	set("long", @LONG
洞庭庙位于君山东北角秋月岭的半山腰。主殿重檐歇山顶、青釉筒
瓦、双弓形山墙，入口门厅塑东西二将把守殿堂。主殿正中是一尊面目
狰狞的黑脸大王柳毅像。柳毅被封王为洞庭王。龙王担心柳毅这白面书
生镇不住水妖陆怪，便命钱塘君做了怪面具，让柳毅白天戴着巡查湖岸，
晚上脱下怪面具，于是，柳毅便由白面书生变成了黑脸大王。
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"out"   : __DIR__"xiaolu8",
		"east"  : __DIR__"yinyangting",
		"west"  : __DIR__"taijiting",
		"north" : __DIR__"dongtingmiao2",
	]));
	set("coor/x", -1660);
	set("coor/y", 2350);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
