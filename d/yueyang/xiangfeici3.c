// Room: /d/yueyang/xiangfeici3.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "湘妃祠正殿");
	set("long", @LONG
正殿上方，悬挂有一块黑底金字匾，上书“渊德侯”。因为相传娥
皇女英殁水后，被天帝封神为“渊德后”，后张之洞修复湘妃庙时，尊
湘妃二神为“渊德侯”，故有此匾。走进正殿，香雾缭绕，大殿内台上
供奉有二妃塑像，四尊侍女塑纷立两旁。据祠里的人讲，二妃塑像刚供
上去时是面带笑容，可是，供了几年，如今二妃皆由笑容转变为凄凄含
泪神情。此中真味谁识？
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"xiangfeici2",
	]));
	set("coor/x", -1660);
	set("coor/y", 2330);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
