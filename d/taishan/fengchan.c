// Room: /d/taishan/fengchan.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "封禅台");
	set("long", @LONG
如今这里是推选天下武林总盟主之处，各路英雄如能技压群雄，比
武夺魁，便能问鼎盟主宝座，成为统领中原武林的领袖。高台上摆放着
汉白玉宝座，盟主便在此坐堂议事。台上高高立着一竿旗，上书：“替
天行道”四个大字。盟主左右各侍立着两位白衣武士，两边都放着一长
排虎皮交椅，时常有武林前辈高手前来参见盟主。
LONG );
	set("exits", ([
		"down" : __DIR__"yuhuang",
		"east" : __DIR__"xiayi",
		"west" : __DIR__"zhengqi",
	]));
	set("objects",([
		"/clone/npc/meng-zhu" : 1,
		__DIR__"npc/wei-shi1" : 4,
	]));
	set("outdoors", "taishan");
	set("coor/x", 410);
	set("coor/y", 630);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
