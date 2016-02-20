// smallbox.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("小铁盒", ({"small box", "box"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
        	set("long",
"这只盒子小得多，只一尺见方。盒中一张笺上写道：“君
是忠厚仁者，葬我骸骨，当酬以重宝秘术。大铁盒开启时
有毒箭射出，愈中书谱地图均假，上有剧毒，以惩贪欲恶
徒。真者在此小铁盒内。”\n");
        	set("unit", "只");
        	set("open_count", 1);
        	set("weight", 1000);
        }
}

void init()
{
        add_action("do_open","open");
}

int do_open()
{
  object ob, me = this_player();
  object ob1 ;
  ob1 = new(__DIR__"smallbox1");
  ob1 -> move(me);
	ob = new("/clone/book/jinshe1");
	if (ob->violate_unique())
	{
		destruct(ob);
		destruct(this_object());
		return notify_fail("铁盒已经被别人打开过了。\n");
	}
  message_vision(HIR 
"$N伸手打开铁盒，盒子里有一本书，上写《金蛇秘笈》四字，用
钳子揭开数页，见写满密密小字，又有许多图画。有的是地图，
有的是武术姿势，更有些兵刃机关的图样。\n" NOR, this_player());
  add("open_count", -1);
  ob -> move(me);
 	destruct(this_object());
  return 1;
}
