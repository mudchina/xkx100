// Room: /d/taishan/chaoyang.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "朝阳洞");
	set("long", @LONG
这里是一个天然石穴，稍加整修，便深广如屋，南辟向阳，旧名迎
阳、云阳。洞后壁线刻元君像。洞南原有乾隆驻跸亭，北有元君殿。洞
东南翠峰崛起，虬松附石，望之如老将军披巾坐鞍马，故名老人寨。下
有朗然子洞，系元初道士刘朗然修真处。洞东北为绝壁，名御风岩。
LONG );
	set("exits", ([
		"southeast" : __DIR__"wudafu",
		"northup"   : __DIR__"duisong",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 360);
	set("coor/y", 690);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
