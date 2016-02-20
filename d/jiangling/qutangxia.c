//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "瞿塘峡");
	set ("long", @LONG
杜甫曾在诗中写道：“白帝高为三峡镇，瞿塘险过百牢关”。从白
帝城向东，便进入长江三峡中最西面的瞿塘峡。它包括风箱峡和错开峡
两段水峡，在三峡中最短，却最为雄伟险峻。
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
		"west" : __DIR__"baidicheng",
		"east" : __DIR__"wuxia",
	]));
  
	set("coor/x", -1510);
	set("coor/y", -2060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
