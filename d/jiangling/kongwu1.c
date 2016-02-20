//Edited by fandog, 01/31/2000

inherit ROOM;
void create ()
{

	set ("short", "空屋");
	set ("long", @LONG
室中空空洞洞，除了一桌、一椅、一床之外，什么东西也没有。床
上挂着一顶夏布白帐子，一床薄被，一个布枕，床脚边放着一双青布女
鞋。只是这一双女鞋，才显得这房间原为一个女子所住。
LONG);

	set("exits", ([ 
		"west" : __DIR__"loudao",
		"north": __DIR__"kongwu2",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1470);
	set("coor/y", -2039);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
