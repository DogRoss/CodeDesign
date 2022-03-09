using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class NodeHandler : MonoBehaviour
{
    public Node root;

    public bool del = false;


    private void Start()
    {
        
    }

    private void Update()   
    {
        if (del)
        {
            DeleteValue(100);
            del = false;
        }
    }

    public void ImplementValue(int val)
    {
        Debug.Log("Implementing values in handler...");
        root.CompareValues(val);
    }

    public void DeleteValue(int val)
    {
        root.FindValue(val).value = 0;
    }
}
