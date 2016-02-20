// Room: /d/taishan/yaocan.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "遥参亭");
	set("long", @LONG
这里为岱庙前庭，旧称草参门、草参亭。古人凡有事于泰山，必先
至此进行简单参拜，而后入庙祭神。亭为二进院落。前院正殿，明清时
祀碧霞元君；两侧为东西配殿；院中有清康熙五十九年同知泰安州事张
奇逢立《禁止舍身碑》。
　　亭前石坊额书“遥参亭”。两侧铁狮对峙，旗杆高竖。坊前为双龙
池。池南为通天街，池西有唐槐一株，后院中立四角亭。
LONG );
	set("exits", ([
		"north" : __DIR__"daimiao",
		"south" : __DIR__"taishanjiao",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 400);
	set("coor/y", 450);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
