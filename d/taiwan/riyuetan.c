// Room: /d/taiwan/riyuetan.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "日月潭");
	set("long", @LONG
日月潭位于玉山之北，能高山之南，有龙湖、珠潭、双潭等称呼，
生活在此一泓潭水四周的邵族族人则称其为「水社海」。日月潭之名，
相传得之于潭中浮岛珠仔屿，以其为界北半形如日轮，南半近似月钩，
如在水社大山或集集大山上俯瞰，更觉所言不虚。日月潭之美在于它四
周翠峰环抱，湖水碧蓝，湖面曲折迤逦，景色优美如画。日月潭八景：
潭中浮屿、潭口九曲、万点渔火、独木番舟、水社朝霞、荷叶重钱、番
家杵声、山水拱秀等，远从清代起，便惊服了文人墨客善感的心。
LONG );
	set("exits", ([
		"northwest" : __DIR__"banxianshe",
	]));
	set("objects", ([
		__DIR__"npc/shaozhuren": 1,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2520);
	set("coor/y", -7010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

