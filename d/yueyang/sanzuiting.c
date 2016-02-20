// Room: /d/yueyang/sanzuiting.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "三醉亭");
	set("long", @LONG
三醉亭，位于岳阳楼北侧，为主楼辅亭之一。四方形高三丈，二层
二檐，歇山顶，碧瓦红柱华丽而庄重。传说八仙之一的吕洞宾曾三次到
岳阳神游，为这里秀美的山、水所迷，每次均在楼内喝得酩酊大醉。亭
内陈设淡雅，一楼厅内屏上绘制有吕洞宾醉酒图。
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"yueyanglou1",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/bangzhong" : 2,
	]));
	set("coor/x", -1450);
	set("coor/y", -2250);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
