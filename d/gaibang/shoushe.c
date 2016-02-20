//room: shoushe.c
inherit ROOM;

void create()
{
	set("short","兽舍");
	set("long", @LONG
这里是丐帮弟子的兽舍。这里豢养了各种猛兽，以供出道的丐帮
弟子使用。兽舍里猛兽长声嘶嚎，老远都听得见。尤其是夜晚听来，
更有是撕心裂肺的惨烈。兽舍里养了一群猪(pig) ，看来是前程不是
很远大。
LONG );
	set("exits",([
		"east"  : __DIR__"pomiao",
	]));
	set("outdoors", "yangzhoue");
	set("item_desc",([
		"pig":
"   ^..^  ^. .^   ^..^   ^..^ ^..^ ^　^  ^..^         ^..^ ^qp^  ^cc^  ^@@^
   (oo) ( o o )  (OO)  (oo ) (@@) (oo)         (00)  (qp) (oo)  (oo)  (oo)

    猪   肥猪   澎恰恰 牙痛  台湾 睡猪 黑暗中 仰泳中 感冒 哭泣 有斜视 近视猪
                型的猪 的猪  土猪       的猪   的猪  的猪 的猪  的猪
",
	]));
	set("objects",([
		"/d/baituo/npc/fox" :1,
		"/d/baituo/npc/wolf" :1,
		"/d/baituo/npc/tiger" :1,
		"/d/baituo/npc/lion" :1,
	]));
	set("coor/x", 60);
	set("coor/y", 60);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}