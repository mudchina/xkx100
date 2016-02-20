//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "太晖观");
	set ("long", @LONG
这里原是明太祖朱元璋第十二子朱柏的王宫。飞楼涌殿，雄甲荆楚，
人称赛武当。在高高的平台上是一座约十米见方的金殿，顶覆铜瓦，骄
阳映照之下，闪光夺目，数里之外，均能看见。
LONG);

	set("exits", ([ 
      "east" : __DIR__"xiaowu",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1510);
	set("coor/y", -2055);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
