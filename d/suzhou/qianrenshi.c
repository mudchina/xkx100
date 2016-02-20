// Room: /d/suzhou/qianrenshi.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "千人石");
	set("long", @LONG
在虎丘山中心，有一块千人石，巨石呈暗紫红色，由南向北倾斜石
面甚平坦，石壁如斧削。传说吴王墓筑成后，其子夫差怕泄露筑墓秘密
假借墓成祝酒观舞之名，将千余名工匠全部杀戮，鲜血渗透石中，成暗
红色。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"erxianting",
		"west"      : __DIR__"disanquan",
		"north"     : __DIR__"shijianshi",
		"northwest" : __DIR__"zhishuang",
		"southwest" : __DIR__"jianchi",
	]));
	set("coor/x", 800);
	set("coor/y", -1020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
