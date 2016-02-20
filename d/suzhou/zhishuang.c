// Room: /d/suzhou/zhishuang.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "致爽阁");
	set("long", @LONG
在千人石西面就是致爽阁，又名伏虎阁，在虎丘塔的西南面，是山
上的最高点。阁名取“四山爽气，日夕西来”之意。旧称“小五台”，
是海涌峰顶。阁外平台宽阔，俯瞰沃野；远眺群峰逶迤，可赏著名上午
“狮子回头看虎丘”一景。深秋季节观成群飞翔的苍鹰，蔚为壮观。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southeast" : __DIR__"qianrenshi",
	]));
	set("objects", ([
		__DIR__"npc/lady1" :1,
	]));
	set("coor/x", 790);
	set("coor/y", -1010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
