// yuzhengong.c 遇真宫
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "遇真宫");
        set("long", @LONG
这里是重阳宫以前的旧址，是王重阳王真人参悟大道之前清修的
地方。后来手创全真教后，此地的布局实在太小，就将重阳宫迁到东
面山上，将此地重新改名为遇真宫，以纪念得道之意。这里很久没有
人来过了，桌椅上都积满了灰尘。
LONG
        );
        set("exits", ([
                "south" : __DIR__"fangzhenqiao",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3140);
	set("coor/y", 150);
	set("coor/z", 190);
	setup();
        replace_program(ROOM);
}