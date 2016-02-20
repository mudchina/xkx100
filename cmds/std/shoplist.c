// shoplist.c
inherit F_CLEAN_UP;

#include <ansi.h>



static mapping *all_shop = ({
        ([
                "id":             "北京",
                "dealer_id":      "jia laoliu",
                "dealer_place":   "/d/beijing/dangpu",
        ]),
        ([
                "id":             "扬州",
                "dealer_id":      "tang nan",
                "dealer_place":   "/d/city/dangpu",
        ]),
        ([
                "id":             "成都",
                "dealer_id":      "yan liu",
                "dealer_place":   "/d/city/dangpu",
        ]),
        ([
                "id":             "佛山",
                "dealer_id":      "lao chaofeng",
                "dealer_place":   "/d/foshan/dangpu",
        ]),
        ([
                "id":             "凌霄",
                "dealer_id":      "chen chaofeng",
                "dealer_place":   "/d/lingxiao/sell",
        ]),
        ([
                "id":             "苏州",
                "dealer_id":      "wang heji",
                "dealer_place":   "/d/suzhou/dangpu",
        ]),
        ([
                "id":             "无锡",
                "dealer_id":      "feng hu",
                "dealer_place":   "/d/wuxi/dangpu",
        ]),
        ([
                "id":             "襄阳",
                "dealer_id":      "qiu hang",
                "dealer_place":   "/d/xiangyang/dangpu",
        ]),
//});
//mapping *all_player_shop = ([
        ([
                "id": 						"北京",
                "dealer_id": 			"huo ji",
                "dealer_place": 	SHOP_DIR"beijing_shop",
        ]),
        ([
                "id": 						"长安",
                "dealer_id": 			"huo ji",
                "dealer_place": 	SHOP_DIR"changan_shop",
        ]),
        ([
                "id": 						"成都",
                "dealer_id": 			"huo ji",
                "dealer_place": 	SHOP_DIR"chengdu_shop",
        ]),
        ([
                "id": 						"扬州",
                "dealer_id": 			"huo ji",
                "dealer_place": 	SHOP_DIR"yangzhou_shop",
        ]),
        ([
                "id": 						"苏州",
                "dealer_id": 			"huo ji",
                "dealer_place": 	SHOP_DIR"suzhou_shop",
        ]),
        ([
                "id": 						"杭州",
                "dealer_id": 			"huo ji",
                "dealer_place": 	SHOP_DIR"hangzhou_shop",
        ]),
        ([
                "id": 						"福州",
                "dealer_id": 			"huo ji",
                "dealer_place": 	SHOP_DIR"fuzhou_shop",
        ]),
        ([
                "id": 						"无锡",
                "dealer_id": 			"huo ji",
                "dealer_place": 	SHOP_DIR"wuxi_shop",
        ]),
        ([
                "id": 						"开封",
                "dealer_id": 			"huo ji",
                "dealer_place": 	SHOP_DIR"kaifeng_shop",
        ]),
        ([
                "id": 						"延平",
                "dealer_id": 			"huo ji",
                "dealer_place": 	SHOP_DIR"yanping_shop",
        ]),
        ([
                "id": 						"泉州",
                "dealer_id": 			"huo ji",
                "dealer_place": 	SHOP_DIR"quanzhou_shop",
        ]),
        ([
                "id": 						"佛山",
                "dealer_id": 			"huo ji",
                "dealer_place": 	SHOP_DIR"foshan_shop",
        ]),
                
});
string query_sell(object me,object seller,string arg,int shop_number);
string makeup_space(string s);
string filter_color(string arg);


int main(object me, string arg)
{
  object dealer;
  string msg="";
  mapping shop;
  int i;
  if (!arg) return notify_fail("你要查什么东西?\n");
  if (time()-me->query("last/query_sell")<10 && !wizardp(me))
    return notify_fail("系统忙，请稍后再试。\n");
  seteuid(getuid());
  for (i=0;i<sizeof(all_shop);i++)
  {
    shop=all_shop[i];
    if (!find_object(shop["dealer_place"]))
    continue;
    dealer=present(shop["dealer_id"],find_object(shop["dealer_place"]));
    if (!dealer) 
    continue;
    msg+=query_sell(me,dealer,arg,i);
  }
  if (!msg || msg== "")
  return notify_fail("没有任何当铺卖这样东西。\n");
  me->set("last/query_sell",time());
  tell_object(me,msg);
  return 1;
}
//dealer.c
// end 

string query_sell(object me,object seller,string arg,int shop_number)
{
        string msg="";
        object *inv;
        object room,*ob,gob;
        int i,j,*count;
        mapping goods, goods_num;
        string *gks;
        string *invstr;
        string *gk;
        int discount;
// 先获取符合条件的货物列表
//处理当铺
   invstr=({});
   ob=({});
   count=({});
   gk=({});
   j=0;
 if (!seller->is_waiter())
 {
   inv=all_inventory(seller);
   for (i = 0; i < sizeof(inv); i++) 
   {
     if (!inv[i]->query("equipped") && !inv[i]->query("money_id"))
     {
     	if (inv[i]->id(arg) || filter_color(inv[i]->name(1)) == arg)
       {
         j=member_array(inv[i]->name()+"/"+inv[i]->query("id"),invstr);
         if ( j==-1 )
         {
           ob += ({inv[i]});
           invstr += ({ inv[i]->name()+"/"+inv[i]->query("id") });
           count += ({1});
         }       
         else   
         	count[j] += 1;
       }
     }
  }
   if (sizeof(ob) <= 0) return "";
/*   for (j =0 ; j<sizeof(ob); j++)
   for (i = 0 ; i < sizeof(inv); i++)
   {
     if (inv[i]->short()==ob[j]->short())
       count[j]++;
   }
*/  msg = HIW+"\n"+all_shop[shop_number]["id"];
  msg+= environment(seller)->query("short");
//  msg+= "情况如下：\n"NOR;
  msg += "：\n"NOR;
  for (j=0 ;j<sizeof(ob);j++)
  msg += sprintf("%30-s%s数量：%3-i %s\n", 
        ob[j]->short(),
        makeup_space(ob[j]->short()), count[j],
        MONEY_D->price_str(ob[j]->query("value") * 6 / 5));
 }
 else  //处理店铺
 {
 	 room = environment(seller);
 	 if (! room->query("shop_type"))  return "";
   if (room->query("ban") &&
     member_array(this_player()->query("id"), room->query("ban")) != -1)
     return "";
   if (! room->query("all_vendor_goods"))   return "";

    goods = room->query("vendor_goods");
   if (!goods)
     return "";
    gks = keys(goods);
    
    discount = 10;
    if (mapp(room->query("invite")))
    discount = room->query("invite")[me->query("id")];
    if (discount <= 0 || discount > 10) discount = 10;
    for (i = 0; i < sizeof(gks); i++)
    {
       call_other(gks[i], "???");
       if (! objectp(find_object(gks[i])))
       {
        log_file("user_vendor", sprintf("No found vendor good:%s\n", gks[i]));
        continue;
       }
       gob = find_object(gks[i]);
       if (!gob) return "";
       if (gob->id(arg) || filter_color(gob->name(1)) == arg) 
       {
////
          j=member_array(gob->name()+"/"+gob->query("id"),invstr);
          if ( j==-1 )
          {
            ob += ({ gob });
            invstr += ({ gob->name()+"/"+gob->query("id") });
            count += ({room->query("vendor_goods_num")[gks[i]]});
            gk += ({ room->query("vendor_goods")[gks[i]] * discount/10 });
          }
//          else
//          	count[j]++;
////
        }
   }
  if (sizeof(ob)<=0) return "";
  msg = HIW+"\n"+all_shop[shop_number]["id"];
  msg+= environment(seller)->query("short");
//  msg+= "情况如下：\n"NOR;
  msg += "：\n"NOR;
  for (j=0;j<sizeof(ob);j++)
  msg += sprintf("%30-s%s数量：%3-i %s\n", 
        ob[j]->short(),
        makeup_space(ob[j]->short()), count[j],
        MONEY_D->price_str(gk[j] ));

 	}
  return msg;
}



string makeup_space(string s)
{
  string *ansi_char = ({
    BLK,   RED,   GRN,   YEL,   BLU,   MAG,   CYN,   WHT,
    BBLK,  BRED,  BGRN,  BYEL,  BBLU,  BMAG,  BCYN,
           HIR,   HIG,   HIY,   HIB,   HIM,   HIC,   HIW,
           HBRED, HBGRN, HBYEL, HBBLU, HBMAG, HBCYN, HBWHT,
    NOR
  });

  string space = s;
  int i, space_count;

  for (i = 0; i < sizeof(ansi_char); i ++)
    space = replace_string(space, ansi_char[i], "", 0);

  space_count = sizeof(s) - sizeof(space);
  if (sizeof(s) >= 30)
    space_count = 30 - sizeof(space);

  space = "";

  for (i = 0; i < space_count; i ++) space += " ";
  return space;
}

string filter_color(string arg)
{
  if(!arg) return "";
  arg = replace_string(arg, BLK, "");
  arg = replace_string(arg, RED, "");
  arg = replace_string(arg, GRN, "");
  arg = replace_string(arg, YEL, "");
  arg = replace_string(arg, BLU, "");
  arg = replace_string(arg, MAG, "");
  arg = replace_string(arg, CYN, "");
  arg = replace_string(arg, WHT, "");
  arg = replace_string(arg, HIR, "");
  arg = replace_string(arg, HIG, "");
  arg = replace_string(arg, HIY, "");
  arg = replace_string(arg, HIB, "");
  arg = replace_string(arg, HIM, "");
  arg = replace_string(arg, HIC, "");
  arg = replace_string(arg, HIW, "");
  arg = replace_string(arg, NOR, "");
/*  arg = replace_string(arg, BBLK, "");
  arg = replace_string(arg, BRED, "");
  arg = replace_string(arg, BGRN, "");
  arg = replace_string(arg, BYEL, "");
  arg = replace_string(arg, BBLU, "");
  arg = replace_string(arg, BMAG, "");
  arg = replace_string(arg, BCYN, "");
  arg = replace_string(arg, HBRED, "");
  arg = replace_string(arg, HBGRN, "");
  arg = replace_string(arg, HBYEL, "");
  arg = replace_string(arg, HBBLU, "");
  arg = replace_string(arg, HBMAG, "");
  arg = replace_string(arg, HBCYN, "");
  arg = replace_string(arg, HBWHT, "");
  arg = replace_string(arg, NOR, "");
*/
  return arg;
}
int help(object me)
{
  write(@HELP
指令格式：shoplist <物品id 或 物品中文名>

          例如 shoplist ren shen
               shoplist 人参
                    
    这个指令让你能查找到指定物品是否在当铺中销售。
 
HELP
  );
  return 1;
}
