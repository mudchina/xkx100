// Room: /heizhao/shiliang2.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "石梁");
	set("long", @LONG
宽约尺许的石梁，横架在两座山峰之间，云雾笼罩，望不见尽
处。这石梁下临深谷，别说行走，只望一眼也不免胆战心惊。空中
时有寒鸦哀鸣，传在耳里，让人心窒腿软不想前行。
LONG );
	set("outdoors", "taoyuan");
	set("exits", ([
		"south"  : __DIR__"shiliang1",
		"north"  : __DIR__"shiliang3",
	]));
	set("coor/x", -5020);
	set("coor/y", -1240);
	set("coor/z", 40);
	setup();
}

int valid_leave(object me, string dir)
{
	object *inv, ob;
	int i;

//	if(wizardp(me)) return 1;

	inv = all_inventory(me);
	if( !sizeof(inv) )
	{
		message_vision(HIW "$N在石梁上晃了一下，差点儿掉入万丈深渊！\n" NOR,me);
		return notify_fail("");
	} else
	{
		switch( random(5) )
		{
			case 0: 
				for (i = 0; i < sizeof(inv); i++ )
				{
				if(inv[i]->query("id")=="huangbu xiaonan")
					{
message_vision(HIM "$N在石梁上一晃，身上的"+inv[i]->name()+"掉入了万丈深渊之中！\n" NOR,me);
						destruct(inv[i]);
					}
				}
				break;
			case 1: 
message_vision(HIR "$N在石梁上晃了两下，一骨碌滚下深渊！\n" NOR,me);
				me->move(__DIR__"shanlu6");
message("vision", HIR"只见" + me->query("name") + "从山上骨碌碌地滚了下来，躺在地上半天爬不起来！\n"NOR, environment(me), me);
				return notify_fail(HIR"你从石梁上滚下来，只觉得浑身伤痛。\n"NOR);
				break;
			default: 
message_vision(HIW "$N在石梁上晃了一下，差点儿掉入万丈深渊！\n" NOR,me);
				break;
		}
        }
	return 1;
}