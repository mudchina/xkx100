// Room: /d/yueyang/qiuyueting.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "秋月亭");
	set("long", @LONG
秋月亭、秋月桥、秋月井皆出自于宋朝画家米芾名画《潇湘八景》
之《洞庭秋月》这个掌故。秋月亭建于君山东侧小山秋月岭上，始建于
宋末，为单层檐六个方亭，亭中有两人观月台。站在亭上可以饱览洞庭
湖月色(moon)。传说米芾就是在这里完成了他的名画《洞庭秋月》。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("item_desc", ([
		"moon" : "
    月下的洞庭，安然恬静如闺阁闲情里的典雅淑女，绝无喧哗，绝无
牵绊，绝无争执，绝无伤害。这是一种奇妙的造化，是洞庭湖在月夜里
展示出来的属于它另一面的阴柔之美，它的美无所不在。\n"
	]));
	set("exits", ([
		"southdown" : __DIR__"qiuyueqiao",
		"northeast" : __DIR__"xiaolu8",
	]));
	set("coor/x", -1670);
	set("coor/y", 2340);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
