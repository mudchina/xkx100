// Room: /d/yueyang/xuanyuantai.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "轩辕台");
	set("long", @LONG
南有一悬崖崖下有龙虎猴三洞，崖上高处就是铸鼎台。铸鼎台又称
轩辕台，传闻轩辕黄帝曾在此铸鼎。江湖每年的丐帮君山大会都在此处
举行，当年黄蓉以少女之身十五岁执掌丐帮，便是在此一举威镇群丐而
获得拥戴，此等艳举空前抑且不再，后辈英豪无缘盛举，抚今追昔，慷
慨万端。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"eastdown" : __DIR__"shijie6",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/ma-dayuan" : 1,
	]));
	set("coor/x", -1790);
	set("coor/y", 2270);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
