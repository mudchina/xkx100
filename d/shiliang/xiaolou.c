// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "小楼");
	set("long", @LONG
这是一座精致的小楼，你走到这里，不由得眼前一耀，先是
闻到一阵幽幽的香气，只见房中点着一支大红烛，照得满室生辉
床上珠罗纱的帐子，白色缎被上绣着一只黄色的凤凰，壁上挂着
一幅工笔仕女图。床前桌上放着一张雕花端砚，几件碧玉玩物，
笔筒中插了大大小小六七支笔，西首一张几上供着一盆兰花，架
子上停着一只白鹦鹉。满室锦绣，连椅子上也绣了花。东边放着
把琴，一位小姐心不在焉地坐在琴的前面。
LONG
	);
	set("exits", ([ 
            "down" : __DIR__"xiaoting",
	]));
        set("objects", ([
		__DIR__"npc/wenyi" : 1,
	]));
	set("coor/x", 1620);
	set("coor/y", -1770);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}