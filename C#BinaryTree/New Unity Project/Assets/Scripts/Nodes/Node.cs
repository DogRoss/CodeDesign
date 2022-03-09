using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Node : MonoBehaviour
{

    public bool isActive = false;

    public int value;

    public Node rightNode = null;
    public Node leftNode = null;

    // Start is called before the first frame update
    void Start()
    {
        if(value == 0)
        {
            isActive = false;
        }
    }

    // Update is called once per frame
    void Update()
    {
        if (isActive)
        {
            gameObject.GetComponent<MeshRenderer>().enabled = true;
        }
        else
        {
            gameObject.GetComponent<MeshRenderer>().enabled = false;
            if (leftNode && leftNode.isActive)
            {
                leftNode.Deactivate();
            }
            if (rightNode && rightNode.isActive)
            {
                rightNode.Deactivate();
            }
        }

        if (value == 0 && isActive)
        {
            MoveUp();
            isActive = false;
        }
        if(value > 0)
        {
            isActive = true;
        }
    }

    public void Deactivate()
    {
        isActive = false;
    }
    public void Activate()
    {
        isActive = false;
    }

    public void MoveUp()
    {
        if (rightNode && rightNode.isActive)
        {
            Debug.Log("//entered right active state");
            value = rightNode.value;
            rightNode.MoveUp();
        }
        else if (leftNode && leftNode.isActive)
        {
            Debug.Log("//entered left active state");
            value = leftNode.value;
            leftNode.MoveUp();
        }
        
    }

    public void CompareValues(int val)
    {
        Debug.Log("//entered '" + val + "' CompareValues function in: " + gameObject.name);
        if(val > value)
        {

            if(rightNode && rightNode.isActive)
            {
                rightNode.CompareValues(val);
            }
            else if(rightNode && !rightNode.isActive)
            {
                Debug.Log("Implementing on right node..." + rightNode.isActive);
                rightNode.Implement(val);
            }
            else if(!rightNode && isActive)
            {
                value = val;
            }
        }
        else if(val < value)
        {
            if (leftNode && leftNode.isActive)
            {
                leftNode.CompareValues(val);
            }
            else if(leftNode && !leftNode.isActive)
            {
                Debug.Log("Implementing on left node...");
                leftNode.Implement(val);
            }
            else if (!leftNode && isActive)
            {
                value = val;
            }
        }
        else
        {
            return;
        }
    }
    public void Implement(int val)
    {
        Debug.Log("//entered implement for: " + gameObject.name);
        value = val;
        isActive = true;
    }

    public Node FindValue(int val)
    {
        Node current = this;

        while (true)
        {
            if (val > value)
            {
                current = current.rightNode ? current.rightNode : null;
            }
            else if (val < value)
            {
                current = current.leftNode;
            }
            else if (val == value)
            {
                return current;
            }
            else
            {
                Debug.Log("value doesnt exist");
                return null;
            }
        }
    }
}
